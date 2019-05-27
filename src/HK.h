#ifndef HK_H
#define HK_H

#include <vector>
#include <cmath>

using namespace std;

unsigned numberOfBitsSet(unsigned value){
    unsigned bits = 0;
    while(value){
        if (value & 1) bits++;
        value = value >> 1;
    }
    return bits;
}

vector<unsigned> combinations(int r, int N){
    vector<unsigned> combos;
    for(unsigned i = 0; i <= pow(2, N); i++)
        if (numberOfBitsSet(i) == r) combos.push_back(i);

    return combos;
}

#endif