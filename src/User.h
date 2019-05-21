#ifndef USER_H
#define USER_H

#include "utils.h"

class User{
private:
    unsigned id, depTol, arrTol;
    Coords source, destination;
    bool driver;
public:
    User(int id, Coords s, Coords d, int dT, int aT);
    unsigned getId() const;
    bool isDriver() const;
    /*bool withinDepTol(simplexTime d) const;
    bool withinArrTol(simplexTime d) const;*/
};

#endif
