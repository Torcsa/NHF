#include "stream.h"


void beolvas (Autopalya& autopalya, std::istream& is){
    size_t cellaDb;
    int autoDb, motorDb, mentoDb;
    std::cout<<"A cellák minimumszáma 10, míg a cellák maximumszáma 120! E kettő érték között adja meg a cellák számát"<<std::endl;
    std::cout<<"A cellák száma: ";
    is>>cellaDb;

    if(cellaDb<10 || cellaDb>120) throw "Cellaszam nem jo";

    Autopalya uj(cellaDb);

    int cella = cellaDb;
    darabszamBeolvasas(is, autoDb, cella,"autok");
    darabszamBeolvasas(is, motorDb, cella,"motrok");
    darabszamBeolvasas(is, mentoDb, cella,"mentok");

    kezdopozicioBeolvasas(is, uj,autoDb, motorDb, mentoDb);

    double szim;
    std::cout<<"Add meg a szimuláció sebességét! Az érték 0-1 között legyen!"<<std::endl;
    is>>szim;
    if(szim<=0 || szim > 1) throw "Szimulacios sebesseg nem megfelelo";
    uj.setSzimSebesseg(szim);

    autopalya = uj;

}

void darabszamBeolvasas(std::istream& is,int& db, int& cella, const char* tipus){
    std::cout<<"Add meg a(z)"<< tipus << "szamat"<<std::endl;
    is>>db;
    if(db<0 || db>cella) throw "Nem jo szam";
    cella -= db;
    if(cella<=0) throw "Hiba";
}


void kezdopozicioBeolvasas(std::istream& is,Autopalya& autopalya,int auto_db, int motor_db, int mento_db){
    size_t tmp;
    if(auto_db>0){
        std::cout<<"\nAdd meg az autok kezdopiziciojat!"<<std::endl;
        for(int i=0; i<auto_db; ++i){
            is>>tmp;
            if(tmp<=0 || tmp>= autopalya.getDb()) throw "Érvénytelen cella!";
            tmp--;
            if(autopalya.getTarolo()[tmp]!= nullptr) throw "Itt mar volt jarmu";
            autopalya.setTarolo()[tmp] = new Auto(tmp);
        }
    }

    if(motor_db>0){
        std::cout<<"\nAdd meg a motorok kezdopiziciojat!"<<std::endl;
        for(int i=0; i<motor_db; ++i){
            is>>tmp;
            if(tmp<=0 || tmp>= autopalya.getDb()) throw "Érvénytelen cella!";
            tmp--;
            if(autopalya.getTarolo()[tmp]!= nullptr) throw "Itt mar volt jarmu";
            autopalya.setTarolo()[tmp] = new Motor(tmp);
        }
    }

    if(mento_db>0){
        std::cout<<"\nAdd meg a mentok kezdopiziciojat!"<<std::endl;
        for(int i=0; i<mento_db; ++i){
            is>>tmp;
            if(tmp<=0 || tmp>= autopalya.getDb()) throw "Érvénytelen cella!";
            tmp--;
            if(autopalya.getTarolo()[tmp]!= nullptr) throw "Itt mar volt jarmu";
            autopalya.setTarolo()[tmp] = new Mento(tmp);
        }
    }
}


void kirajzol(const Autopalya& autopalya){
    for(size_t i =0;i<autopalya.getDb();++i){
        std::cout<<" _";
    }
    std::cout<<std::endl;

    for(size_t i =0;i<autopalya.getDb();++i){
        if(autopalya.getTarolo()[i]!= nullptr) std::cout<<"|"<<autopalya.getTarolo()[i]->getSzimbolum();
        //else if(autopalya.getTarolo()[i]== nullptr) std::cout<<"|"<<"X";
        else std::cout<<"| ";
    }
    std::cout<<"|"<<std::endl;
    /*
    for(size_t i =0;i<autopalya.getDb();++i){
        std::cout<<"-";
    }
     */
}



































/*
void darabszamBeolvasas(std::istream& is,int& auto_db, int& motor_db, int& mento_db, int cella){
    std::cout<<"Autók száma: ";
    is>>auto_db;
    if(auto_db<0 || auto_db>cella) throw "Autoszam nem jo";
    cella -= auto_db;

    std::cout<<"Motorok szama: ";
    is>>motor_db;
    if(motor_db<0 || motor_db>cella) throw "Motorszam nem jo";
    cella -= motor_db;

    std::cout<<"Mentok szama: ";
    std::cin>>mento_db;
    if(mento_db<0 || mento_db>1) throw "Mentoszam nem jo";
    cella -= mento_db;
    if(cella<=0) throw "Nem megfelelo mennyisegu jarmu";
}
 */