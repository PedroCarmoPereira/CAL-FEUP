#include "RideShare.h"
#include <map>

/**
 * RideShare constructor.
**/
RideShare::RideShare(Graph<Node> graph, Graph<Node> graph_dest, int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap, vector<User> u):driver(Driver(id, s, d, dep, arr, dT, aT, cap)){
    this->graph = graph;
    this->graph_dest = graph_dest;
    this->users = u;
}

/**
 * Creates a graph with all the relevante nodes (Driver, User location and User destination).
**/
void RideShare::trimGraph(){
    vector<Node> nodesToKeep;
    vector<Node> nodesToKeep_dest;
    nodesToKeep.push_back(this->graph.findVertex(this->driver.getSourceID())->getInfo());
    nodesToKeep_dest.push_back(this->graph_dest.findVertex(this->driver.getDestinationID())->getInfo());
    for(vector<User>::const_iterator it = this->users.begin(); it != this->users.end(); it++){
        nodesToKeep.push_back(this->graph.findVertex(it->getSourceID())->getInfo());
        nodesToKeep_dest.push_back(this->graph_dest.findVertex(it->getDestinationID())->getInfo());
    }
    Graph<Node> trimmedGraph;    
    for(vector<Node>::const_iterator it0 = nodesToKeep.begin(); it0 != nodesToKeep.end(); it0++)
        trimmedGraph.addVertex(this->graph.findVertex(*it0)->getInfo());

    Graph<Node> trimmedGraph_dest;    
    for(vector<Node>::const_iterator it0 = nodesToKeep_dest.begin(); it0 != nodesToKeep_dest.end(); it0++)
        trimmedGraph_dest.addVertex(this->graph_dest.findVertex(*it0)->getInfo());

    for(vector<Node>::const_iterator it1 = nodesToKeep.begin(); it1 != nodesToKeep.end(); it1++)
        for(vector<Node>::const_iterator it2 = nodesToKeep.begin(); it2 != nodesToKeep.end(); it2++){
            if(it1 == it2) continue;
            Node n1 = Node(*it1);
            Node n2 = Node(*it2);
            this->graph.dijkstraShortestPath(n1);
            const vector<Node> &v = this->graph.getPath(n1, n2);
            if(!v.empty())trimmedGraph.addEdge(n1, n2, weightPath(this->graph, v));
    
        }
    for(vector<Node>::const_iterator it1 = nodesToKeep_dest.begin(); it1 != nodesToKeep_dest.end(); it1++)
        for(vector<Node>::const_iterator it2 = nodesToKeep_dest.begin(); it2 != nodesToKeep_dest.end(); it2++){
            if(it1 == it2) continue;
            Node n1 = Node(*it1);
            Node n2 = Node(*it2);
            this->graph_dest.dijkstraShortestPath(n1);
            const vector<Node> &v = this->graph_dest.getPath(n1, n2);
            if(!v.empty())trimmedGraph_dest.addEdge(n1, n2, weightPath(this->graph_dest, v));
    
        }

    this->graph = trimmedGraph;
    this->graph_dest = trimmedGraph_dest;
}

/**
 * remove users that are not accessible
**/
void RideShare::removeUsers(){

    //cout << this->users.size() << endl;
    Node d_n1 = this->graph.findVertex(this->driver.getSourceID())->getInfo();
    Node d_n2 = this->graph_dest.findVertex(this->driver.getDestinationID())->getInfo();
    vector<Node> v;
    for(vector<User>::const_iterator it = this->users.begin(); it != this->users.end(); ){
        Node u_n1 = this->graph.findVertex(it->getSourceID())->getInfo();
        Node u_n2 = this->graph_dest.findVertex(it->getDestinationID())->getInfo();
        this->graph.dijkstraShortestPath(d_n1);
        v = this->graph.getPath(d_n1, u_n1);
        if(v.size() == 0){
            //cout << "remove source" << endl;
            it = this->users.erase(it);
        }else{
            this->graph_dest.dijkstraShortestPath(d_n2);
            v = this->graph_dest.getPath(d_n2, u_n2);
            if(v.size() == 0){
                //cout << "remove dest" << endl;
                it = this->users.erase(it);
            }else
                it++;
        }
    }
    //cout << this->users.size() << endl;


}

Graph<Node> RideShare::getGraphSource(){
    return this->graph;
}

Graph<Node> RideShare::getGraphDest(){
    return this->graph_dest;
}

vector<Node> RideShare::getSource_nodes(){
    return this->source_nodes;
}

vector<Node> RideShare::getDest_nodes(){
    return this->dest_nodes;
}

/**
 * choose the best users to pick up
**/
void RideShare::pickUp(){
    map<int, pair<Node,Node> > map; 
    vector<Node> v;
    Node d_n1 = this->graph.findVertex(this->driver.getSourceID())->getInfo();
    Node d_n2 = this->graph_dest.findVertex(this->driver.getDestinationID())->getInfo();
    int weight = 0;
    for(vector<User>::const_iterator it = this->users.begin(); it != this->users.end(); it++){
        Node u_n1 = this->graph.findVertex(it->getSourceID())->getInfo();
        Node u_n2 = this->graph_dest.findVertex(it->getDestinationID())->getInfo();
        this->graph.dijkstraShortestPath(d_n1);
        this->graph_dest.dijkstraShortestPath(d_n2);
        v = this->graph.getPath(d_n1, u_n1);
        weight = weightPath(this->graph, v);
        v = this->graph_dest.getPath(d_n2, u_n2);
        weight += weightPath(this->graph_dest, v);
        map.insert(make_pair(weight, make_pair(u_n1, u_n2)));
    }
    vector<Node> v_s;
    vector<Node> v_d;
    for(auto u : map){
        if(this->driver.getCurrOcup() < this->driver.getCapacity()){
            v_s.push_back(u.second.first);
            v_d.push_back(u.second.second);
            this->driver.setCurrOcup(this->driver.getCurrOcup()+1);
        }
        else
            break;    
    }
    this->source_nodes = v_s;
    this->dest_nodes = v_d;
    
}
