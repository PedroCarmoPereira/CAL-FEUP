#ifndef USER_H
#define USER_H

//#include "utils.h"
#include <ctime>

typedef struct tm tms;

class User{
private:
    unsigned id, depTol, arrTol;/*depTol & arrTol expressed in minutes*/
    tms departure, arrival;
    int sourceID, destinationID;
    bool driver;
public:

    /**
     * Constructors
    **/
    User(){};
    User(int id, int sourceID, int destinationID, tms dep, tms arr, int dT, int aT, bool driving);

    /**
     * Get functions
    **/
    unsigned getId() const;
    int getDepTol()const;
    int getArrTol()const;
    tms getDeparture()const;
    tms getArrival()const;
    int getSourceID() const;
    int getDestinationID() const;

    /**
     * Set funtions
    **/
    void setId(int id);
    void setDepTol(int depTol);
    void setArrTol(int arrTol);
    void setDeparture(tms departure);
    void setArrival(tms arrival);
    void setSourceID(int sourceId);
    void setDestinationID(int destinationId);
    
    
    /**
     * Verifies if the user is the driver.
    **/
    bool isDriver() const;

    /**
     *  
    **/
    bool withinArrTol(tms eta);
    bool withinDepTol(tms etd);
};

#endif
