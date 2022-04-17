#ifndef NHF_MOTOR_H
#define NHF_MOTOR_H

#include "jarmu.h"
#include <iostream>


class Motor : public Jarmu{
    static const int elozesiMaxSebesseg;
    static const int maxSebesseg;
    static const char szimbolum;
public:
    Motor(size_t poz, Tipus t=MOTOR, int akt=0): Jarmu(poz, t, akt){}
    char getSzimbolum() const override { return szimbolum; }

    int kovetkezoSebesseg(Autopalya& autopalya);

};


#endif //NHF_MOTOR_H
