#include "RideShare.h"
#include <map>
#include "utils.h"

#define DIST_PORTO_FAFE		68300

/**
 * RideShare constructor.
**/
RideShare::RideShare(Graph<Node> graph, Graph<Node> graph_dest, Driver driver, vector<User> u){
    this->graph = graph;
    this->driver = driver;
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
 * Remove users that are not accessible. 
 * Meaning, all the independent nodes are removed. 
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

/**
 * Get funtions
**/
Graph<Node> RideShare::getGraphSource(){ return this->graph;}
Graph<Node> RideShare::getGraphDest(){ return this->graph_dest;}
vector<Node> RideShare::getSource_nodes(){ return this->source_nodes;}
vector<Node> RideShare::getDest_nodes(){ return this->dest_nodes;}

/**
 * Choose the best users to pick up based on the distance and time restrictions.
**/
void RideShare::pickUp(){
    multimap<int, pair<Node,Node> > nodes_map; 
    multimap<int, User > map_users; 

    //Frist pruning: based on the distance
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
        nodes_map.insert(make_pair(weight, make_pair(u_n1, u_n2)));
        map_users.insert(make_pair(weight,*it ));
    }
    //Second pruning: based on the time restrictions
    tms dep, arr;
    dep = this->driver.getDeparture();
    arr = this->driver.getArrival();
    time_t d_departure = mktime( &dep);
    time_t d_arrival = mktime( &arr);
    time_t u_departure;
    time_t u_arrival; 
    vector<User> car;
    //Removes all the user with a departure time before the departure time of the driver.
    for(multimap<int, User >::iterator it = map_users.begin(); it != map_users.end(); ++it){
        dep = (*it).second.getDeparture();
        u_departure = mktime( &dep) + (*it).second.getDepTol()*60;
        if(u_departure < d_departure ){      
            multimap<int, User >::iterator remove = it;
            map_users.erase(remove);
        }
    }

    //checks if the driver has time to perform the trip with all the current users.
    //If not, removes the user with the least time to travel.
    bool isDriverReady = false;
    bool isRemoved = false;
    while(!isDriverReady){
        double totalDistance = DIST_PORTO_FAFE;
        if(map_users.size() == 0) break;
        //Calculate the distance the driver has to travel in the worst case scenario.
        for(multimap<int, User >::iterator it = map_users.begin(); it != map_users.end(); ++it){
            if(++it == map_users.end())
                break;
            else --it;

            //Begin with the driver
            if(it == map_users.begin()){
                totalDistance += (*it).first;
                continue;
            }

            //Current user
            Vertex<Node> it_1_origin = *this->graph.findVertex(it->second.getSourceID());
            Vertex<Node> it_1_destiny = *this->graph_dest.findVertex(it->second.getDestinationID());

            //Next user
            ++it;
            Vertex<Node> it_2_origin = *this->graph.findVertex(it->second.getSourceID());
            Vertex<Node> it_2_destiny = *this->graph_dest.findVertex(it->second.getDestinationID());
            --it;

            //Get distance of edges of the two vertex pairs
            for(auto edge : it_1_origin.getAdj()){
                if(edge.getDest()->getInfo().id == it_2_origin.getInfo().id)
                    totalDistance += edge.getWeight();
            }
            for(auto edge : it_2_destiny.getAdj()){
                if(edge.getDest()->getInfo().id == it_1_destiny.getInfo().id)
                    totalDistance += edge.getWeight();
            }
        }

        //transforming total distance into time
        time_t totalTime = weightTotime(totalDistance);

        //Estimate the time of arrival of the driver in the worst case scenario 
        time_t estimateArrival = d_departure + totalTime;

        tms driverArr = this->driver.getArrival();
        tms driverDep = this->driver.getDeparture();
        time_t driverTime = (mktime(&driverArr) + this->driver.getArrTol()*60);
        cout << driverTime << endl;
        cout << estimateArrival << endl;
        if(driverTime < estimateArrival){

            //find the user with the least time to perform the trip
            multimap<int, User >::iterator remove = map_users.begin();
            for (multimap<int, User >::iterator it = map_users.begin(); it != map_users.end(); ++it){

                tms itArr = (*it).second.getArrival();
                //check if the use has time to do the trip with the current number of users
                if((mktime(&itArr) + it->second.getArrTol()*60) < estimateArrival){
                    //Checks if the user is the worst
                    //if the current user has less time than the previous worst user, saves the current.
                    tms worstDep = (*remove).second.getDeparture();
                    tms worstArr = (*remove).second.getArrival();

                    tms currentDep = (*it).second.getDeparture();
                    tms currentArr = (*it).second.getArrival();
                    time_t timeToTravelWorst = (mktime(&worstDep)+(*remove).second.getDepTol()*60) - (mktime(&worstArr));
                    time_t timeToTravelCurrent = (mktime(&currentDep)+(*it).second.getDepTol()*60) - (mktime(&currentArr));
                    if(timeToTravelCurrent < timeToTravelWorst){
                        remove = it;
                    }

                    isRemoved = true;
                }
            }
            if(isRemoved){
                map_users.erase(remove);
            }
        }
        else isDriverReady = true;

    }


    //removes all the users that don't have time to perform the trip
    isRemoved = true;
    bool isUserReady = false;
    while(!isUserReady){

        isRemoved = false;
        double totalDistance = DIST_PORTO_FAFE;
        if(map_users.size() == 0) break;
    
        //Calculate the distance the driver has to travel in the worst case scenario.
        for(multimap<int, User >::iterator it = map_users.begin(); it != map_users.end(); ++it){
            if(++it == map_users.end())
                break;
            else --it;

            //Begin with the driver
            if(it == map_users.begin()){
                totalDistance += (*it).first;
                continue;
            }

            //Current user
            Vertex<Node> it_1_origin = *this->graph.findVertex(it->second.getSourceID());
            Vertex<Node> it_1_destiny = *this->graph_dest.findVertex(it->second.getDestinationID());

            //Next user
            ++it;
            Vertex<Node> it_2_origin = *this->graph.findVertex(it->second.getSourceID());
            Vertex<Node> it_2_destiny = *this->graph_dest.findVertex(it->second.getDestinationID());
            --it;

            //Get distance of edges of the two vertex pairs
            for(auto edge : it_1_origin.getAdj()){
                if(edge.getDest()->getInfo().id == it_2_origin.getInfo().id)
                    totalDistance += edge.getWeight();
            }
            for(auto edge : it_2_destiny.getAdj()){
                if(edge.getDest()->getInfo().id == it_1_destiny.getInfo().id)
                    totalDistance += edge.getWeight();
            }
        }

        //transforming total distance into time
        time_t totalTime = weightTotime(totalDistance);

        //Estimate the time of arrival of the driver in the worst case scenario 
        time_t estimateArrival = d_departure + totalTime;
        //find the user with the least time to perform the trip
        multimap<int, User >::iterator remove = map_users.begin();
        for (multimap<int, User >::iterator it = map_users.begin(); it != map_users.end(); ++it){

            tms itArr = (*it).second.getArrival();

            //check if the use has time to do the trip with the current number of users
            if((mktime(&itArr) + it->second.getArrTol()*60) < estimateArrival){
                //Checks if the user is the worst
                //if the current user has less time than the previous worst user, saves the current.
                tms worstDep = (*remove).second.getDeparture();
                tms worstArr = (*remove).second.getArrival();

                tms currentDep = (*it).second.getDeparture();
                tms currentArr = (*it).second.getArrival();
                time_t timeToTravelWorst = (mktime(&worstDep)+(*remove).second.getDepTol()*60) - (mktime(&worstArr));
                time_t timeToTravelCurrent = (mktime(&currentDep)+(*it).second.getDepTol()*60) - (mktime(&currentArr));
                if(timeToTravelCurrent < timeToTravelWorst){
                    remove = it;
                }
                isRemoved = true;  
            }
        }
        if(isRemoved){
            map_users.erase(remove);
        }else isUserReady = true;
    }

    //Inserts the most valid users in the users vectors based on the capacity.
    vector<Node> v_s;
    vector<Node> v_d;
    for(auto u : map_users){
        if(this->driver.getCurrOcup() < this->driver.getCapacity()){
            Node u_n1 = this->graph.findVertex(u.second.getSourceID())->getInfo();
            Node u_n2 = this->graph_dest.findVertex(u.second.getDestinationID())->getInfo();
            v_s.push_back(u_n1);
            v_d.push_back(u_n2);
            this->driver.setCurrOcup(this->driver.getCurrOcup()+1);
        }
        else
            break;    
    }
    this->source_nodes = v_s;
    this->dest_nodes = v_d;
}
