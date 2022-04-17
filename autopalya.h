#ifndef NHF_AUTOPALYA_H
#define NHF_AUTOPALYA_H

#include <iostream>
#include "jarmu.h"

class Jarmu;

class Autopalya {
    Jarmu** tarolo;
    size_t db;
    double szimSebesseg;
    static const size_t tobblet;

public:
    Autopalya(size_t meret = 0):tarolo(new Jarmu*[meret+tobblet]), db(meret){
        for(size_t i=0; i<db+tobblet ; ++i){
            tarolo[i] = nullptr;
        }
    }

    size_t getDb() const { return db; }
    void setDb(size_t x) { db = x; }

    size_t getTobblet()const { return tobblet; }


    Jarmu** getTarolo() const { return tarolo; }
    Jarmu** setTarolo() { return tarolo; }

    double getSzimSebesse() const { return szimSebesseg; }
    void setSzimSebesseg(double x) { szimSebesseg = x; }


    //  Kell egy fv, ami kap egy Jarművet és visszaadja az előtte 10, utána 5 cellával levő cellákat
    Jarmu** jarmuKornyezet(const Jarmu& jarmu)const;

    void jarmuAthelyezes();

    bool nemUresAutopalya();

};



#endif //NHF_AUTOPALYA_H
