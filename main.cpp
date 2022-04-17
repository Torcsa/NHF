#include <iostream>
#include "main.h"

int main() {

    srand(time(NULL));

    //Kezdeti szöveg kiírása


    //Beolvasás
    Autopalya uj;
    try{
        beolvas(uj,std::cin);
    }catch(const char*){
        std::cout<<"Bejott a catch-be";
    }
    //A beolvasás után rajzoljuk ki az autópályát



    kirajzol(uj);
    Sleep(1000);

    //Ez lesz a szimuláció lényegi része!
    //A szimuláció addig fut, amig az autópálya ki nem ürült.
    while(uj.nemUresAutopalya()){

        //Léptessük a járműveket
        uj.jarmuAthelyezes();
        //Majd várjunk, hogy látható legyen a változás
        Sleep(1000);
        kirajzol(uj);

        //Az iteráció ismétlődhet;
    }

    std::cout<<"A szimulacio vegetert!"<<std::endl;











    return 0;
}
