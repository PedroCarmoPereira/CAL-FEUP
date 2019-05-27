#ifndef HK_H
#define HK_H

#include <vector>
#include <cmath>

using namespace std;

unsigned numberOfBitsSet(unsigned value);

void combinations_aux(unsigned set, unsigned at, unsigned r, unsigned N, vector<unsigned> & subsets);

vector<unsigned> combinations(int r, int N);

bool notIn(unsigned i, unsigned subset);

#endif