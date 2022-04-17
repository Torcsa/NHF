#include "motor.h"

const int Motor::elozesiMaxSebesseg = 6;
const int Motor::maxSebesseg = 4;
const char Motor::szimbolum = 'm';

int Motor::kovetkezoSebesseg(Autopalya& autopalya){
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

    //Mentóőautó - JÓ
    for(size_t i = 0; i<cellakMogotte;++i){
        if(tmp[getPoz()-(i+1)]->getTipus()==MENTO) return getAkt()-1;
    }

    //Motor előzi éppen - JÓ
    for(size_t i = 0; i<getAkt()+1 && i<cellakMogotte;++i){
        if(tmp[getPoz()-(i+1)]->getTipus()==MOTOR && tmp[getPoz()-(i+1)]->getAkt() > getAkt()) return getAkt();
            //Itt két eset van:
            //                  Vagy még nem előzött és most megkezdheti az előzést
            //                  Vagy már előzött és nem akarjuk, hogy láncolva legyen az előzés, emiatt lassítjuk
            //Honnan tudjuk, hogy előzött-e már?
            //
        if(tmp[getPoz()-(i+1)]->getAkt() < getAkt() && getAkt()>Motor::maxSebesseg) return getAkt()-1;
    }

    //Motor előz
    for(size_t i = 0;i<getAkt() && getPoz()+i<autopalya.getDb();++i){
        if(tmp[getPoz()+(i+1)]->getAkt()<getAkt()){
          if(getAkt()<Motor::elozesiMaxSebesseg) return getAkt()+1;
          else return Motor::elozesiMaxSebesseg;
        }
    }

    //Előtte levő üres cellákban nála gyorsabb motor/mentő van
    for(size_t i = 0; i<getAkt() && getPoz()+i<autopalya.getDb();++i){
        if(tmp[getPoz()+(i+1)]->getAkt()>=getAkt()) return getAkt();
    }

    //
    size_t cellakElotte = 0;
    while(tmp[getPoz()+cellakElotte+1] == nullptr){
        ++cellakElotte;
    }
    if(cellakElotte>getAkt() && getAkt()<Motor::maxSebesseg) return getAkt()+1;
    if(cellakElotte<getAkt()) return cellakElotte;
    return getAkt();

}