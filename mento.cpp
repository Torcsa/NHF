#include "mento.h"


const int Mento::maxSebesseg = 6;
const char Mento::szimbolum = 'M';

int Mento::kovetkezoSebesseg(Autopalya& autopalya){
    //A mento sebessége 6, ha már felgyorsult arra
    //Mivel a kezdosebessége alapból 0, addig gyorsítjuk, amíg 6 nem lesz a sebessége.
    //
    //
    if(getAkt()<Mento::maxSebesseg){
        setAkt(getAkt()+1);
        return getAkt();
    }
    return getAkt();

}