#ifndef NHF_AUTO_H
#define NHF_AUTO_H

#include "jarmu.h"
#include <iostream>
#include <ctime>
#include <cstdlib>



class Auto : public Jarmu{
    static const int maxSebesseg;
    static const char szimbolum;
    bool lassit;

public:

    Auto(size_t poz, Tipus t = AUTO, int akt = 0): Jarmu(poz, t, akt){}

    char getSzimbolum() const override { return szimbolum; }
    int kovetkezoSebesseg(Autopalya& autopalya) override ;

};


#endif //NHF_AUTO_H
