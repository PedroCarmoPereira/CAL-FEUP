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

    RideShare(Graph<Node> graph,Graph<Node> graph_dest,  int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap, vector<User> users);
    void trimGraph();
    void removeUsers();
    void pickUp();
    Graph<Node> getGraphSource();
    Graph<Node> getGraphDest();
    vector<Node> getSource_nodes();
    vector<Node> getDest_nodes();

};

#endif
