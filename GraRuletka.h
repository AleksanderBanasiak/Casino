//
// Created by Olek Banasiak on 02.06.2023.
//

#ifndef UNTITLED_GRARULETKA_H
#define UNTITLED_GRARULETKA_H
#include <iostream>
using namespace std;

class Gracz;


class GraRuletka {
public:
    void ruletka(Gracz &gracz);
    void ruletkaGra(Gracz &gracz);
    static void zasadyRuletka();
    static int losowanieRuletka();
    static void menuRuletka();
    static void losowanie();
    void r1(Gracz &gracz);
    void r2(Gracz &gracz);
    void r3(Gracz &gracz);
    void r4(Gracz &gracz);
    void r5(Gracz &gracz);
    void r6(Gracz &gracz);
    void r7(Gracz &gracz);
    void r8(Gracz &gracz);
    void r9(Gracz &gracz);
    void r10(Gracz &gracz);
    static void nieUdaloSieRuletka(Gracz &gracz, int ilosc, int wylosowanaLiczba);
    static void udaloSieRuletka(Gracz &gracz, int ilosc, int wylosowanaLiczba);
    int obstawianieRuletka(Gracz &gracz);
    friend void zapisDoPliku(Gracz &gracz, int ilosc);
    static void menuGry();

};


#endif //UNTITLED_GRARULETKA_H
