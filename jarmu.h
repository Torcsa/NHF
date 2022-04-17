#ifndef NHF_JARMU_H
#define NHF_JARMU_H

#include <iostream>
#include "autopalya.h"

class Autopalya;

class Jarmu{
protected:
    enum Tipus{AUTO, MOTOR, MENTO};
private:
    //A pozíció 0-tól van!
    size_t pozicio;
    Tipus tipus;
    int aktSebesseg;

public:
    Jarmu(size_t poz, Tipus t,int akt=0): pozicio(poz), tipus(t), aktSebesseg(akt){}

    void setTipus(Jarmu::Tipus t){ this->tipus = t; }
    Tipus getTipus() const { return tipus; }

    int getAkt()const{ return aktSebesseg; }
    void setAkt(int x) { aktSebesseg = x; }


    virtual char getSzimbolum() const = 0;
    size_t getPoz() const{ return pozicio; }
    void setPoz(int x){ pozicio = x; }

    virtual int kovetkezoSebesseg(Autopalya& autopalya) = 0;

    virtual ~Jarmu(){}
};


#endif //NHF_JARMU_H
