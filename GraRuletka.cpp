//
// Created by Olek Banasiak on 02.06.2023.
//
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Gracz.h"
#include "GraRuletka.h"
#include "Plik.h"
using namespace std;
Plik plik2;
void GraRuletka::menuGry() {
    cout << "[1]-Graj" << endl;
    cout << "[2]-Zasady gry" << endl;
    cout << "[3]-Wyjscie" << endl;

}
int GraRuletka::losowanieRuletka(){
    srand(time(NULL));
    int los;
    int los2;
    for(int i=0; i< 20; i++){
        los = rand() % 37;
        cout << los<< "\r";
        Sleep(200);
    }

    return los2= rand()%37;

}
void GraRuletka::losowanie(){
    cout << "Losowanie ";
    Sleep(400);
    cout << ". ";
    Sleep(400);
    cout << ". ";
    Sleep(400);
    cout << ". " << endl;
}
void GraRuletka::menuRuletka(){
    cout << "[1]- 0" <<endl;
    cout << "[2]- Liczby 1-18" <<endl;
    cout << "[3]- Liczby 19-36" <<endl;
    cout << "[4]- Pierwsze 12" <<endl;
    cout << "[5]- Drugie 12" <<endl;
    cout << "[6]- Trzecie 12" <<endl;
    cout << "[7]- Kolor czerwony" <<endl;
    cout << "[8]- Kolor czarny" <<endl;
    cout << "[9]- Parzyste" <<endl;
    cout << "[10]- Nieparzyste" <<endl;
    cout << "[11]- Wyjscie" <<endl;
}

void GraRuletka::ruletkaGra(Gracz &gracz) {
    system("cls");
    bool flaga;
    int wybor;
    do{
        menuGry();
        cin >> wybor;
        switch (wybor) {
            case 1:ruletka(gracz);break;
            case 2:zasadyRuletka();break;
            case 3: flaga= false;system("cls"); break;
            default: cout << "Podales zla wartosc! "<< endl;
        }
    } while (flaga);

}
void GraRuletka::zasadyRuletka() {
    system("cls");
    cout << "Po wcisnieciu Graj nastepuje losowanie cyfry, gdy wyloswoana cyfra bedzie z  podanego zakresu gracz otrzymuje mnoznik \n" ;
    cout << "0 - Wartosc postawiona * 35" <<endl;
    cout << "Liczby 1-18 - Wartosc postawiona * 2" <<endl;
    cout << "Liczby 19-36 - Wartosc postawiona * 2" <<endl;
    cout << "Pierwsze 12 - Wartosc postawiona * 3" <<endl;
    cout << "Drugie 12 - Wartosc postawiona * 3" <<endl;
    cout << "Trzecie 12 - Wartosc postawiona * 3" <<endl;
    cout << "Kolor czerwony - Wartosc postawiona * 2 (czyli 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36)" <<endl;
    cout << "Kolor czarny - Wartosc postawiona * 2 (czyli 6,15,24,33,2,8,11,17,20,26,29,35,4,10,13,22,28,31)" <<endl;
    cout << "Parzyste - Wartosc postawiona * 2" <<endl;
    cout << "Nieparzyste - Wartosc postawiona * 2" <<endl << endl;

}
void GraRuletka::udaloSieRuletka(Gracz &gracz, int ilosc, int wylosowanaLiczba) {
    system("cls");
    ilosc *=2;
    cout << "Brawo udalo Ci sie wygrac poniewaz wylosowana liczba to "<< wylosowanaLiczba <<endl;
    gracz.dodajPieniadz(ilosc);
    Sleep(3000);
    gracz.getDane();
    cout << endl;
}
void GraRuletka::nieUdaloSieRuletka(Gracz &gracz, int ilosc, int wylosowanaLiczba) {
    system("cls");
    cout << "Niestety nie udalo Ci sie wygrac poniewaz wylosowana liczba to "<< wylosowanaLiczba <<endl;
    Sleep(3000);
    gracz.getDane();
    cout << endl;
}

bool tablicaRuletka(int liczba){
    int tab[]={6,15,24,33,2,8,11,17,20,26,29,35,4,10,13,22,28,31};


    for(int i=0; i<18; i++){
        if(liczba != tab[i]){
            continue;
        }else{
            return true;
        }


    }
    return false;
}

void GraRuletka::r1(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {

        ilosc /= 2;
        ilosc *= 35;
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();


        if (wylosowanaLiczba == 0) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }
}void GraRuletka::r2(Gracz &gracz){

    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();


        if (wylosowanaLiczba < 19) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }
}void GraRuletka::r3(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();


        if (wylosowanaLiczba > 18) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}void GraRuletka::r4(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        ilosc *= 1.5;
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();


        if (wylosowanaLiczba < 13) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}void GraRuletka::r5(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        ilosc *= 1.5;
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();


        if (wylosowanaLiczba > 12 && wylosowanaLiczba < 25) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}void GraRuletka::r6(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        ilosc *= 1.5;
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();


        if (wylosowanaLiczba > 24) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}void GraRuletka::r7(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        losowanie();

        int wylosowanaLiczba = losowanieRuletka();

        bool flaga = tablicaRuletka(wylosowanaLiczba);
        if (!flaga) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);
        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }


}void GraRuletka::r8(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        losowanie();

        int wylosowanaLiczba = losowanieRuletka();

        bool flaga = tablicaRuletka(wylosowanaLiczba);
        if (flaga) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);
        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}void GraRuletka::r9(Gracz &gracz){
    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        losowanie();

        int wylosowanaLiczba = losowanieRuletka();

        if (wylosowanaLiczba % 2 == 0) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}void GraRuletka::r10(Gracz &gracz){

    int ilosc = obstawianieRuletka(gracz);
    if(ilosc!=-1) {
        losowanie();
        int wylosowanaLiczba = losowanieRuletka();

        if (wylosowanaLiczba % 2 == 1) {
            udaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
            plik2.zapisDoPliku(gracz, ilosc * 2);

        } else {
            nieUdaloSieRuletka(gracz, ilosc, wylosowanaLiczba);
        }
    }

}
int GraRuletka::obstawianieRuletka(Gracz &gracz){
    int wartosc;
    cout << "Ile chcesz postawic: ";
    cin >> wartosc;
    if(wartosc<=0){
        cout << "Nie mozesz tyle postawic!"<< endl;
        return -1;
    }else {


        while (gracz.getPieniadz() - wartosc < 0) {
            cout << "Nie masz tyle pieniedzy!!" << endl << "Ile chcesz postawic: ";
            cin >> wartosc;
        }
        gracz.wezPieniadz(wartosc);

        return wartosc;
    }
}
void GraRuletka::ruletka(Gracz &gracz) {

    system("cls");
    bool flaga = true;
    int wybor;
    gracz.getDane();
    cout << endl;



    do {
        menuRuletka();
        cout << "Co chcesz obstawic: ";
        cin >> wybor;
        switch (wybor) {
            case 1:
                r1(gracz);
                break;
            case 2:
                r2(gracz);
                break;
            case 3:
                r3(gracz);
                break;
            case 4:
                r4(gracz);
                break;
            case 5:
                r5(gracz);
                break;
            case 6:
                r6(gracz);
                break;
            case 7:
                r7(gracz);
                break;
            case 8:
                r8(gracz);
                break;
            case 9:
                r9(gracz);
                break;
            case 10:
                r10(gracz);
                break;
            case 11:
                system("cls");
                flaga = false;
                break;
        }
    } while (flaga);




}