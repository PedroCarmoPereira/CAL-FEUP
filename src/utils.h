#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "graphviewer.h"

using namespace std;

typedef enum {AVEIRO, BRAGA, COIMBRA, ERMESINDE, FAFE, GONDOMAR, LISBOA, MAIA, PORTO, VISEU, PORTUGAL} location;

typedef struct coords_t{
    int x_or_lat, y_or_lon;
} Coords;

typedef struct simple_time_t{
    bool pastMidnight;
    unsigned int hour;
    unsigned int min;
} simplexTime;

void setFiles(location loc, string &nodeFile, string &edgeFile);

void readFiles(GraphViewer *gv, string nodeFile, string edgeFile);

#endif
