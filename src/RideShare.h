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

    RideShare(Graph<Node> graph,Graph<Node> graph_dest,  int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap, vector<User> users);
    void trimGraph();
    void removeUsers();
    vector<Node> getPath_pickUp();
    Graph<Node> getGraphSource();
    Graph<Node> getGraphDest();

};

#endif
