#ifndef USER_H
#define USER_H

#include "utils.h"

class User{
private:
    int id;
    Coords source, destination;
    simplexTime departure, arrival;
    unsigned int depTol, arrTol;
public:
    User(int id, Coords s, Coords d, simplexTime dep, simplexTime arr, int dT, int aT);
    bool withinDepTol(simplexTime d) const;
    bool withinArrTol(simplexTime d) const;
};

#endif
