#include "RideShare.h"

RideShare::RideShare(Graph<Node> graph, int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap, vector<User> u):driver(Driver(id, s, d, dep, arr, dT, aT, cap)){
    this->graph = graph;
    this->users = u;
}

Graph<Node> RideShare::trimGraph(){
    vector<Node> nodesToKeep;
    nodesToKeep.push_back(this->graph.findVertex(this->driver.getSourceID())->getInfo());
    nodesToKeep.push_back(this->graph.findVertex(this->driver.getDestinationID())->getInfo());
    for(vector<User>::const_iterator it = this->users.begin(); it != this->users.end(); it++){
        nodesToKeep.push_back(this->graph.findVertex(it->getSourceID())->getInfo());
        nodesToKeep.push_back(this->graph.findVertex(it->getDestinationID())->getInfo());
    }

    Graph<Node> trimmedGraph;    
    for(vector<Node>::const_iterator it0 = nodesToKeep.begin(); it0 != nodesToKeep.end(); it0++)
        trimmedGraph.addVertex(this->graph.findVertex(*it0)->getInfo());

    for(vector<Node>::const_iterator it1 = nodesToKeep.begin(); it1 != nodesToKeep.end(); it1++)
        for(vector<Node>::const_iterator it2 = nodesToKeep.begin(); it2 != nodesToKeep.end(); it2++){
            if(it1 == it2) continue;
            Node n1 = Node(*it1);
            Node n2 = Node(*it2);
            this->graph.dijkstraShortestPath(n1);
            const vector<Node> &v = this->graph.getPath(n1, n2);
            trimmedGraph.addEdge(n1, n2, weightPath(this->graph, v));
        }

    return trimmedGraph;
}