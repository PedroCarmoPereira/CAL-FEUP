#include "User.h"

User::User(int id, Coords s, Coords d, int dT, int aT){
    this->id = id;
    this->source = s;
    this->destination = d;
    this->depTol = dT;
    this->arrTol = aT;
}

bool User::isDriver() const{
    return this->driver;
}

unsigned User::getId()const{return this->id;}

