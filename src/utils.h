#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "graphviewer.h"

using namespace std;

typedef enum {AVEIRO, BRAGA, COIMBRA, ERMESINDE, FAFE, GONDOMAR, LISBOA, MAIA, PORTO, VISEU, PORTUGAL} location;


void setFiles(location loc, string &nodeFile, string &edgeFile);

void readFiles(GraphViewer *gv, string nodeFile, string edgeFile);

#endif
