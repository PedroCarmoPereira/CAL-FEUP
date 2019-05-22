#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "Graph.h"
#include "graphviewer.h"

using namespace std;

typedef struct coords_t{
    int x_or_lat;
    int y_or_lon;
} Coords;

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

int edgeWeight(Vertex <int> n1, Vertex <int> n2);

Graph <Node> readFiles(string nodeFile, string edgeFile);

void graphViewer(GraphViewer *gv, Graph <Node> * rideSharing);

#endif
