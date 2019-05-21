#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

typedef enum {AVEIRO, BRAGA, COIMBRA, ERMESINDE, FAFE, GONDOMAR, LISBOA, MAIA, PORTO, VISEU, PORTUGAL} location;


void setFiles(location loc, string &nodeFile, string &edgeFile);

#endif
