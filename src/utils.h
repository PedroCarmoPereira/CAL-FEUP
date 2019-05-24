#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "User.h"
#include "Graph.h"
#include "graphviewer.h"

using namespace std;

#define MAX_SPEED   13.89 /* m/s to be used to calculate time or roughly 50 km/h */

typedef struct coords_t{
    int x_or_lat;
    int y_or_lon;
} Coords;

Coords coords(int x, int y);

class Node{
    Coords coords;
    public:
        int id;
        Node();
        Node(int id);
        Node(int id, Coords c);
        Node(const Node & n);
        bool operator==(const Node &node1) const;
        Node & operator=(const Node & node);
        Coords getCoords() const;
};

typedef enum {AVEIRO, BRAGA, COIMBRA, ERMESINDE, FAFE, GONDOMAR, LISBOA, MAIA, PORTO, VISEU, PORTUGAL} location;

void setFiles(location loc, string &nodeFile, string &edgeFile);

double edgeWeight(Vertex <Node> n1, Vertex <Node> n2);

Graph <Node> readFiles(string nodeFile, string edgeFile);

double weightPath(Graph <Node> &g, const vector<Node > &v);

time_t weightTotime(double w);

void graphViewer(GraphViewer *gv, Graph <Node> * rideSharing);

vector <User> readUsers(string File);

#endif
