#ifndef USER_H
#define USER_H

#include "utils.h"
#include <ctime>

typedef struct tm tms;

class User{
private:
    unsigned id, depTol, arrTol;/*depTol & arrTol expressed in minutes*/
    tms departure, arrival;
    int sourceID, destinationID;
    bool driver;
public:
    User(int id, int sourceID, int destinationID, tms dep, tms arr, int dT, int aT, bool driving);
    unsigned getId() const;
    int getSourceID() const;
    int getDestinationID() const;
    bool isDriver() const;
    bool withinArrTol(tms eta);
    bool withinDepTol(tms etd);
};

#endif
