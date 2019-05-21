#include "User.h"

User::User(int id, Coords s, Coords d, simplexTime dep, simplexTime arr, int dT, int aT){
    this->id = id;
    this->source = s;
    this->destination = d;
    this->departure = dep;
    this->arrival = arr;
    this->depTol = dT;
    this->arrTol = aT;
}
/*
bool User::withinArrTol(simplexTime a) const {
    if (a.hour < this->arrival.hour && !this->arrival.pastMidnight) return true;
    if (a.hour > this->arrival.hour && this->arrival.pastMidnight) return true;
    return false;
}
*/
