#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"
#include "utils.h"

class Driver : public User {
    unsigned capacity;
    unsigned currOcup;
    tms eta;
    
    public:

    /**
     * Constructores
    **/
    Driver():User(){};
    Driver(int id, int s, int d, tms dep, tms arr, int dT, int aT, unsigned cap);

    /**
     * Operator overload.
     * Implemented to provide the property of atribuing the value of a driver constructor to a driver instance. 
    **/
    Driver & operator = (const Driver & d){
        this->setId(d.getId());
        this->setSourceID(d.getSourceID());
        this->setDestinationID(d.getDestinationID());
        this->setDeparture(d.getDeparture());
        this->setArrival(d.getArrival());
        this->setDepTol(d.getDepTol());
        this->setArrTol(d.getArrTol());
        this->capacity = d.getCapacity();

        return *this;
    }

    /**
     * Set funtion
    **/
    void setCurrOcup(int oc);

    /**
     * Get functions
    **/
    unsigned getCapacity() const;
    unsigned getCurrOcup() const;
};

#endif
