//
// Created by Olek Banasiak on 22.05.2023.
//

#include <iostream>
using namespace std;

#ifndef UNTITLED_GRACZ_H
#define UNTITLED_GRACZ_H


class Gracz {

    string imie;
    int iloscPieniedzy;

    public:
    Gracz(string="Nieznany", int=2137);
    void setDane();
    void getDane();
    int getPieniadz();
    void wezPieniadz(int ile);
    string getImie();
    void dodajPieniadz(int ile);




};


#endif //UNTITLED_GRACZ_H
