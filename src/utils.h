#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "Graph.h"
#include "graphviewer.h"

using namespace std;

typedef enum {AVEIRO, BRAGA, COIMBRA, ERMESINDE, FAFE, GONDOMAR, LISBOA, MAIA, PORTO, VISEU, PORTUGAL} location;

typedef struct coords_t{
    int x_or_lat, y_or_lon;
} Coords;

void setFiles(location loc, string &nodeFile, string &edgeFile);

Graph <Coords> readFiles(string nodeFile, string edgeFile);

#endif
