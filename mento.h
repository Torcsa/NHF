#ifndef NHF_MENTO_H
#define NHF_MENTO_H

#include "jarmu.h"
#include <iostream>


class Mento : public Jarmu{
    static const int maxSebesseg;
    static const char szimbolum;

public:
    Mento(size_t poz, Tipus t=MENTO, int akt = 0): Jarmu(poz, t, akt){}
    char getSzimbolum() const override { return szimbolum; }

    int kovetkezoSebesseg(Autopalya& autopalya)override;
};


#endif //NHF_MENTO_H
