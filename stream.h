#ifndef NHF_STREAM_H
#define NHF_STREAM_H
#include "autopalya.h"
#include "jarmu.h"
#include "auto.h"
#include "motor.h"
#include "mento.h"



void beolvas (Autopalya& autopalya, std::istream& is);
void darabszamBeolvasas(std::istream& is,int& auto_db, int& motor_db, int& mento_db, int cella);
void kezdopozicioBeolvasas(std::istream& is,Autopalya& autopalya,int auto_db, int motor_db, int mento_db);

void kirajzol(const Autopalya& autopalya);


////////////////////////////////////////////////////////


void darabszamBeolvasas(std::istream& is,int& db, int& cella, const char* tipus);









#endif //NHF_STREAM_H
