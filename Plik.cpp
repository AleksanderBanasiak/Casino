//
// Created by Olek Banasiak on 02.06.2023.
//


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>
#include <set>
#include <bits/stdc++.h>
#include "Plik.h"
#include "GraJednoreki.h"
#include "Gracz.h"

using namespace std;


void Plik::zapisDoPliku(Gracz &gracz, int ilosc) {


    fstream plik;
    plik.open("wyniki.txt", ios::out | ios::app);


    plik << gracz.getImie() << endl;
    plik << ilosc << endl;

    plik.close();

}


void Plik::sortowanie() {
    int licznik = 0;


    fstream plik;
    plik.open("wyniki.txt", ios::in);

    if(plik.good()== false){
        cout << "Plik nie istnieje";
    }
    string linia;
    int linia2;

    multimap<int, string, greater<int> > map;

    do{
        plik >> linia;
        plik >> linia2;
        map.insert(make_pair(linia2, linia));


    } while (!plik.eof());
    plik.close();

    multimap<int, string>::iterator it;

    system("cls");


            for (it = map.begin(); it != map.end(); ++it) {
                licznik++;
                cout << licznik << ": $" << (*it).first << ", " << (*it).second << endl;

            }
            Sleep(4000);
            cout << endl;

}