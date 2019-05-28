#ifndef RIDE_SHARE_H
#define RIDE_SHARE_H

#include <vector>
#include "utils.h"
#include "Graph.h"
#include "User.h"
#include "Driver.h"

class RideShare {
public:
    Graph<Node> graph;
    Graph<Node> graph_dest;
    Driver driver;
    vector<User> users;
    vector<Node> source_nodes;
    vector<Node> dest_nodes;

    /**
     * Contructor
    **/
    RideShare(Graph<Node> graph, Graph<Node> graph_dest,  Driver driver, vector<User> users);

    void trimGraph();
    void removeUsers();
    void pickUp();

    /**
     * Get funtions
    **/
    Graph<Node> getGraphSource();
    Graph<Node> getGraphDest();
    vector<Node> getSource_nodes();
    vector<Node> getDest_nodes();

};

#endif
