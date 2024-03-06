//
// Created by Olek Banasiak on 04.06.2023.
//
#include <iostream>
using namespace std;
#ifndef UNTITLED_GRABLACKJACK_H
#define UNTITLED_GRABLACKJACK_H
class Gracz;
class Plik;

class GraBlackJack{

public:

    static void menuBlackJack();
    static void zasadyBlackJack();
    void blackJackGra(Gracz &gracz);
    void blackJack(Gracz &gracz);
    static void losowanieKart(string wylosowaneKarty[], string talia[]);
    static void menuBlackJackDobieranie();
    void blackJackDobieranie(Gracz &gracz, string kartaKomputera1, string kartaKomputera2, string kartaKomputera3, string kartaGracza1, string kartaGracza2,string kartaGracza3, int wartoscKartyK1, int wartoscKartyK2,int wartoscKartyK3,int wartoscKartyG1,int wartoscKartyG2,int wartoscKartyG3, int koncowaWartosc);
    void blackJackPass(Gracz &gracz, string kartaKomputera1, string kartaKomputera2, string kartaGracza1, string kartaGracza2, int wartoscKartyK1, int wartoscKartyK2,int wartoscKartyG1,int wartoscKartyG2, int koncowaWartosc);
    static void losowanie();
    static int zamianaWartosci(string karta);




};


#endif //UNTITLED_GRABLACKJACK_H
