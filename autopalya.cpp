#include "autopalya.h"

const size_t Autopalya::tobblet=6;


Jarmu** Autopalya::jarmuKornyezet(const Jarmu& jarmu)const {
    if (jarmu.getPoz() >= 10) { return tarolo + jarmu.getPoz() - 10; }
    return tarolo;
}


void Autopalya::jarmuAthelyezes(){
    for(size_t i=0;i<db;++i){
        //std::cout<<"jarmuAthelyezes iteracio: "<<db-(i+1)<<std::endl;
        if(tarolo[db-(i+1)]!= nullptr){
            int kovSebesseg = tarolo[db-(i+1)]->kovetkezoSebesseg(*this);
            //Itt valszeg az lesz, hogy 6-tal hosszabb lesz a tároló, mint az input
            //Ha a láthatatlan cellákra lépnek a járművek, akkor felszabadítjuk őket.

            //Meg kell nézni, hogy ahova lépne, ott van-e jármű -> ha van, akkor mögé kell besorolni
            if(tarolo[db-(i+1)+kovSebesseg]!=nullptr){
                //Csere, de a sebességének megfelelő egyel előbbi cellába rakjuk a járművet
                int lassitasiMertek = 0;
                while(tarolo[db-(i+1)+kovSebesseg-lassitasiMertek]!= nullptr){
                    lassitasiMertek++;
                }
                //Megtalálja az első üres cellát -> oda kell rakni a motrot, a sebességét annyival kell csökkenteni -> drasztikus lassítás is lehet
                Jarmu* tmp = tarolo[db-(i+1)];
                tarolo[db-(i+1)] = nullptr;
                tarolo[db-(i+1)+kovSebesseg-lassitasiMertek] = tmp;
                //Kell visszajelzés, hogy a sebessége nem is annyi volt, csökkentjük a lassítási mértékkel (mivel, ugye ennyi cellával elé rakjuk)
                tarolo[db-(i+1)+kovSebesseg-lassitasiMertek]->setAkt(tarolo[db-(i+1)+kovSebesseg]->getAkt()-lassitasiMertek);
            }else{
                //Csere
                Jarmu* tmp = tarolo[db-(i+1)];
                tarolo[db-(i+1)] = nullptr;
                tarolo[db-(i+1)+kovSebesseg] = tmp;
                //Át kell állítani a pozícioját a járműnek
                tarolo[db-(i+1)+kovSebesseg]->setPoz(db-(i+1)+kovSebesseg);
                //Illetve majd nézd meg, hogy át lesz e állítva az aktuális sebesség
            }

            //Most kell megvizsgálni, hogy az utolsó pár cellában van-e a jármű.
            for(size_t i = db;i<db+tobblet;++i){
                //ha ezen a pozíción nem nullptr van, akkor ott egy jármű, ez pedig azt jelenti, hogy leért az autópályáról
                if(tarolo[i]!= nullptr) delete tarolo[i];
            }
            //Ez a jármű a helyére lett rakva, ha kiment az autópályáról, akkor le lett szedve az autópályáról, jöhet a következő jármű
        }
    }
}

bool Autopalya::nemUresAutopalya(){
    for(size_t i=0;i<db;++i){
        //std::cout<<"nemUresAutopalya iteracio: "<<i<<std::endl;
        if(tarolo[i]!= nullptr) return true;
    }
    return false;
}