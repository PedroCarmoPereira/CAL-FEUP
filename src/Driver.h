#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"
#include "utils.h"

class Driver : public User {
    const unsigned capacity;
    unsigned currOcup;
    tms eta;
    public:
    Driver(int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap);
    void setCurrOcup(int oc);
    unsigned getCapacity() const;
    unsigned getCurrOcup() const;
};

#endif
