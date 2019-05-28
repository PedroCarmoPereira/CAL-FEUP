#include "User.h"

/**
 * Constructors
**/
User::User(int id, int sourceID, int destinationID, tms dep, tms arr, int dT, int aT, bool driving){
    this->id = id;
    this->sourceID = sourceID;
    this->destinationID = destinationID;
    this->arrival = arr;
    this->departure = dep;
    this->depTol = dT;
    this->arrTol = aT;
    this->driver = driving;
}

/**
 * Get functions
**/
unsigned User::getId()const{return this->id;}
int User::getDepTol()const{ return this->depTol;}
int User::getArrTol()const{ return this->arrTol;}
tms User::getDeparture()const{ return this->departure;}
tms User::getArrival()const{ return this->arrival;}
int User::getSourceID() const{ return this->sourceID;}
int User::getDestinationID() const{ return this->destinationID;}

/**
 * Set funtions
**/
void User::setId(int id){this->id = id;}
void User::setDepTol(int depTol){this->depTol = depTol;}
void User::setArrTol(int arrTol){this->arrTol = arrTol;}
void User::setDeparture(tms departure){this->departure = departure;}
void User::setArrival(tms arrival){this->arrival = arrival;}
void User::setSourceID(int sourceId){this->sourceID = sourceId;}
void User::setDestinationID(int destinationId){this->destinationID = destinationId;}

/**
 * Verifies if the user is the driver.
**/
bool User::isDriver() const{ return this->driver;}


bool User::withinArrTol(tms eta){

    time_t arrWindow = mktime(&this->arrival) + this->arrTol*60;
    time_t etaT = mktime(&eta);
    return etaT <= arrWindow;
}

bool User::withinDepTol(tms etd){

    time_t depWindow = mktime(&this->departure) + this->depTol*60;
    time_t etdT = mktime(&etd);
    return etdT <= depWindow;
}
