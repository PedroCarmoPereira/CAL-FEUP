#include <vector>
#include <cmath>
#include "HK.h"

using namespace std;

unsigned numberOfBitsSet(unsigned value){
    unsigned bits = 0;
    while(value){
        if (value & 1) bits++;
        value = value >> 1;
    }
    return bits;
}

void combinations_aux(unsigned set, unsigned at, unsigned r, unsigned N, vector<unsigned> & subsets){
    int elementsLeftToPick = N - at;
    if (elementsLeftToPick < r) return;
    if (r == 0) subsets.push_back(set);
    else {
        for(int i = at; i < N; i++){
            set ^= (1 << i);
            combinations_aux(set, i + 1, r - 1, N, subsets);
            set ^= (1 << i);
        }
    }
}

vector<unsigned> combinations(int r, int N){
    vector<unsigned> combos;
    combinations_aux(0, 0, r, N, combos);
    return combos;
}

bool notIn(unsigned i, unsigned subset){
    return ((1 << i) & subset) == 0;
}

