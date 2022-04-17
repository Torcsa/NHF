#include "auto.h"

const int Auto::maxSebesseg = 4;
const char Auto::szimbolum = 'A';

int Auto::kovetkezoSebesseg(Autopalya& autopalya) {
    //std::cout<<"Mondd, hogy ide jottel be pls!!"<<std::endl;
    //Mitől függ a következő sebesség?
    //Először
    //Meg kell nézni, hogy mögötte 10 blokkon belül van-e mentő --> az aktualis sebesség -1 lesz a sebessége
    //      //Ez pl motor esetében is igaz --> azaz, ha éppen előzne a motor, de mögötte mentő van, akkor lelassít
    //      //Ekkor mérlegelje, hogy mennyire van előtte az autó
    // Ha NINCS MENTO:
    //      Meg kell nézni, hogy az aktuális sebessége - legyen x - annyi blokkot hátrafelé menve van e az autó sebességénél
    //      nagyobb sebességű motor --> ha van, akkor előzve van az autó --> sebessége marad, mint az előző
    // Ha NINCS MENTO, NEM ELŐZIK
    //      Megnezi az előtte levő üres cellák:
    //          Ha az aktuális sebesség számú cellát megnézzük előtte, és ennyi cellán belül van nála nagyobb sebességű motor
    //          vagy mentő (autó nem lehet - tehát jármű) --> akkor tartja az aktuális sebességét
    //          Ha NINCS ILYEN
    //              Ha az üres cellák száma nagyobb vagy ==, mint az aktuális sebessége a, akkor a sebessége nő 1-el ha a sebessége
    //              kisebb a max sebességénél, ha maxsebesség marad
    //                  -Ekkor jön be a 0,15-ös valószínűséggel, hogy a sebessége kisebb lesz 1-el
    size_t cellakMogotte = this->getPoz()<10 ? this->getPoz() : 10;

    Jarmu** tmp = autopalya.jarmuKornyezet(*this);
    //Mentóőautó
    for(size_t i = 0; i<cellakMogotte;++i){
        if(tmp[i]!=nullptr && tmp[i]->getTipus()==MENTO){
            setAkt(getAkt()-1);
            return getAkt();
        }
    }
    //std::cout<<"Nincs mentoauto az auto mogott 10 cellaval!"<<std::endl;
    //Motor előzi éppen
    for(size_t i = 0; i<getAkt()+1 && i< cellakMogotte;++i){
        if(autopalya.getTarolo()[getPoz()-(i+1)]!=nullptr && autopalya.getTarolo()[getPoz()-(i+1)]->getTipus()==MOTOR && autopalya.getTarolo()[getPoz()-(i+1)]->getAkt() > getAkt()){
            return getAkt();
        }
    }
    //std::cout<<"Nem elozi eppen motor!"<<std::endl;

    //Előtte levő üres cellákban nála gyorsabb motor/mentő van
    for(size_t i = 0; i<getAkt() && getPoz()+i<autopalya.getDb();++i){
        if(autopalya.getTarolo()[getPoz()+(i+1)]!=nullptr && autopalya.getTarolo()[getPoz()+(i+1)]->getAkt()>=getAkt()){
            return getAkt();
        }
    }
    //std::cout<<"Nincs elotte nala gyorsabb motor vagy mento!"<<std::endl;

    //IDE KELL A MEGFELELŐ VALÓSZÍNŰGÉGŰ LASSULÁST MÉG BELEVINNI

    ////////////////////////////////////////////////////////////////
    size_t cellakElotte = 0;
    while((getPoz()+cellakElotte+1) < (autopalya.getDb()+autopalya.getTobblet()) && autopalya.getTarolo()[getPoz()+cellakElotte+1] == nullptr){
        ++cellakElotte;
    }
    int val = rand() % 100+1;
    if(val<=15 && getAkt()>0) lassit = true;
    else lassit = false;

    std::cout<<"Cellak elotte: "<<cellakElotte<<std::endl;
    std::cout<<"getAkt(): "<<getAkt()<<std::endl;

    //Ha van előtte több üres cella, mint a sebessége és nem max sebességgel megy
    if(cellakElotte>getAkt() && getAkt()<Auto::maxSebesseg){
        if(!lassit)setAkt(getAkt()+1);
        else setAkt(getAkt());
        return getAkt();
    }

    //Ha van előtte több üres cella, mint a sebessége, de max sebességgel megy
    if(cellakElotte>getAkt() && getAkt()==Auto::maxSebesseg){
        if(!lassit) return getAkt();
        else { setAkt(getAkt()-1); return getAkt(); }
    }
    //Ha nincs előtte több üres cella, mint amekkora a sebessége, akkor a sebessége az előtt levő üres cellákkal lesz egyenlő

    if(!lassit)setAkt(cellakElotte);
    else setAkt(cellakElotte-1);
    return getAkt();
}
