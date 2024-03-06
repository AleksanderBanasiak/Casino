//
// Created by Olek Banasiak on 02.06.2023.
//
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "GraJednoreki.h"
#include "Gracz.h"
#include "Plik.h"
using namespace std;
Plik plik1;
void GraJednoreki::losowanie(){
    cout << "Losowanie ";
    Sleep(400);
    cout << ". ";
    Sleep(400);
    cout << ". ";
    Sleep(400);
    cout << ". " << endl;
}
void GraJednoreki::menuJednoreki() {
    cout << "[1]-Graj" << endl;
    cout << "[2]-Zasady gry" << endl;
    cout << "[3]-Wyjscie" << endl;

}
void GraJednoreki::jednorekiBandytaGra(Gracz &gracz) {
    system("cls");
    bool flaga;
    int wybor;
    do{
        menuJednoreki();
        cin >> wybor;
        switch (wybor) {
            case 1:jednorekiBandyta(gracz);break;
            case 2:zasadyJednoreki();break;
            case 3: flaga= false;system("cls"); break;
            default: cout << "Podales zla wartosc! "<< endl;
        }
    } while (flaga);

}

void GraJednoreki::zasadyJednoreki() {
    system("cls");
    cout << "Po wcisnieciu graj nastepuje losowanie 3 znakow, gdy podaczas gry wypadna 3 te same znaki po sobie, gracz otrzymuje mnoznik \n" ;
    cout << char(245) << "- Wartosc postawiona * 1,2"<< endl;
    cout << char(55) << "- Wartosc postawiona * 5"<< endl;
    cout << char(174) << "- Wartosc postawiona * 0,5"<< endl;
    cout << char(88) << "- Wartosc postawiona * 3"<< endl;
    cout << char(63) << "- Wartosc postawiona * 2"<< endl << endl;


}
void GraJednoreki::jednorekiBandyta(Gracz &gracz) {
    int wartosc;


    system("cls");
    gracz.getDane();


    srand(time(NULL));

    cout << endl << "Ile chcesz postawic: ";
    cin >> wartosc;
    if(wartosc<=0){
        cout << "Nie mozesz tyle postawic"<< endl;
    }else{


    if (gracz.getPieniadz() - wartosc < 0) {
        cout << "Nie masz tyle pieniedzy!!" << endl;
    } else {

        losowanie();
        gracz.wezPieniadz(wartosc);


        char tab1[3];

        char tablica[5];
        tablica[0] = 245;
        tablica[1] = 55;
        tablica[2] = 174;
        tablica[3] = 88;
        tablica[4] = 63;

        int d = wartosc;
        for (int i = 0; i < 5; i++) {

            int e = rand() % 5;
            tab1[i] = tablica[e];
            cout << tab1[i] << "\r";
            tab1[0] = tab1[i];
            Sleep(400);
        }
        for (int i = 0; i < 5; i++) {
            int e = rand() % 5;
            tab1[i + 1] = tablica[e];
            cout << tab1[0] << " " << tab1[i + 1] << "\r";
            tab1[1] = tab1[i];
            Sleep(400);
        }

        for (int i = 0; i < 5; i++) {
            if (i < 4) {
                int e = rand() % 5;
                tab1[i + 2] = tablica[e];
                cout << tab1[0] << " " << tab1[1] << " " << tab1[i + 2] << "\r";
                tab1[2] = tab1[i + 2];

            } else {
                int e = rand() % 5;
                tab1[i + 2] = tablica[e];
                cout << tab1[0] << " " << tab1[1] << " " << tab1[i + 2];
                tab1[2] = tab1[i + 2];

            }
            Sleep(400);
        }

        string wynik;
        for (int i = 0; i < 3; i++) {
            wynik += tab1[i];
        }


        wartosc = d;


        int koncowaWartosc;


        if (wynik == "777") {
            koncowaWartosc = wartosc * 5;
            gracz.dodajPieniadz(koncowaWartosc);
            cout << endl << "Brawo udalo Ci sie wygrac " << koncowaWartosc << endl;
            Sleep(2000);
            plik1.zapisDoPliku(gracz, koncowaWartosc);

        } else if (wynik == "XXX") {
            koncowaWartosc = wartosc * 3;
            gracz.dodajPieniadz(koncowaWartosc);
            cout << endl << "Brawo udalo Ci sie wygrac " << koncowaWartosc << endl;
            Sleep(2000);
            plik1.zapisDoPliku(gracz, koncowaWartosc);
        } else if (wynik == "???") {
            koncowaWartosc = wartosc * 2;
            gracz.dodajPieniadz(koncowaWartosc);
            cout << endl << "Brawo udalo Ci sie wygrac " << koncowaWartosc << endl;
            Sleep(2000);
            plik1.zapisDoPliku(gracz, koncowaWartosc);
        } else if (wynik == "§§§") {
            koncowaWartosc = wartosc * 1.2;
            gracz.dodajPieniadz(koncowaWartosc);
            cout << endl << "Brawo udalo Ci sie wygrac " << koncowaWartosc << endl;
            Sleep(2000);
            plik1.zapisDoPliku(gracz, koncowaWartosc);
        } else if (wynik == "«««") {
            koncowaWartosc = wartosc * 0.5;
            gracz.dodajPieniadz(koncowaWartosc);
            cout << endl << "Brawo udalo Ci sie wygrac " << koncowaWartosc << endl;
            Sleep(2000);
            plik1.zapisDoPliku(gracz, koncowaWartosc);
        } else {
            cout << endl << "Niestety nie udalo Ci sie wygrac, z twojego konta zabrano $" << wartosc << endl;
            Sleep(3000);
        }


        system("cls");
        gracz.getDane();
        cout << endl;


    }
    }
}


