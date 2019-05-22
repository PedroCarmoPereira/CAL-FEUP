#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "Graph.h"
#include "graphviewer.h"

using namespace std;

typedef enum {AVEIRO, BRAGA, COIMBRA, ERMESINDE, FAFE, GONDOMAR, LISBOA, MAIA, PORTO, VISEU, PORTUGAL} location;

void setFiles(location loc, string &nodeFile, string &edgeFile);

int edgeWeight(Vertex <int> n1, Vertex <int> n2);

Graph <int> readFiles(string nodeFile, string edgeFile);

void graphViewer(GraphViewer *gv, Graph <int> * rideSharing);

#endif
