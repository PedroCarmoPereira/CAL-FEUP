#ifndef USER_H
#define USER_H

#include "utils.h"
#include <ctime>

typedef struct tm tms;

class User{
private:
    unsigned id, depTol, arrTol;/*depTol & arrTol expressed in minutes*/
    tms departure, arrival;
    Coords source, destination;
    bool driver;
public:
    User(int id, Coords s, Coords d, tms dep, tms arr, int dT, int aT, bool driving);
    unsigned getId() const;
    bool isDriver() const;
    bool withinArrTol(tms eta);
    bool withinDepTol(tms etd);
};

#endif
