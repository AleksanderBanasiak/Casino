//
// Created by Olek Banasiak on 02.06.2023.
//

#include <iostream>
using namespace std;

#ifndef UNTITLED_GRAJEDNOREKI_H
#define UNTITLED_GRAJEDNOREKI_H

class Gracz;
class Plik;


class GraJednoreki {



public:
    void losowanie();
    void jednorekiBandyta(Gracz &gracz);
    void menuJednoreki();
    void jednorekiBandytaGra(Gracz &gracz);
    void zasadyJednoreki();
    friend void zapisDoPliku(Gracz &gracz, int ilosc);







};


#endif //UNTITLED_GRAJEDNOREKI_H
