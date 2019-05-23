#include "Driver.h"

Driver::Driver(int id, Coords s, Coords d, tms dep, tms arr, int dT, int aT, unsigned cap):User(id, s, d, dep, arr, dT, aT, true), capacity(cap){}

void Driver::setCurrOcup(int co){
    this->currOcup = co;
}

unsigned Driver::getCapacity() const{
    return this->capacity;
}

unsigned Driver::getCurrOcup() const{
    return this->currOcup;
}
