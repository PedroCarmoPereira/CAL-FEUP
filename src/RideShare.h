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
    Driver driver;
    vector<User> users;

    RideShare(Graph<Node> graph, int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap, vector<User> users);
    Graph<Node> trimGraph();

};

#endif
