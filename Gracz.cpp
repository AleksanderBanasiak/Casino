//
// Created by Olek Banasiak on 22.05.2023.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include "Gracz.h"


using namespace std;

bool poprawnoscImienia(string_view imie)
{
    return all_of(imie.begin(), imie.end(), [](char ch) {
        return (isalpha(ch) || isspace(ch));
    });
}
void Gracz::setDane() {
    string input;
    bool isDigit;
    bool czy;
    cout << "Podaj swoje imie: ";
    cin >> imie;
        while (!poprawnoscImienia(imie)) {
            cout << "Podaj poprawne imie: ";
            cin >> imie;
        }
        do {
            isDigit= true;

            cout << "Ile chcesz wplacic pieniedzy: ";
            cin >> input;
            for (char c: input) {
                if (!isdigit(c)) {
                    isDigit = false;
                    break;
                }
            }

            if (isDigit) {
                czy= false;
                iloscPieniedzy = stoi(input);
            } else{
                czy= true;
            }
        }while(czy);

}void Gracz::getDane() {
    cout << imie << ", $" << iloscPieniedzy;

}string Gracz::getImie() {
    return  imie;

}int Gracz::getPieniadz() {
    return iloscPieniedzy;

}void Gracz::dodajPieniadz(int ile) {
    iloscPieniedzy +=ile;

}

void Gracz::wezPieniadz(int ile) {
    iloscPieniedzy -=ile;

}
Gracz::Gracz(string i, int p) {


    imie = i;
    iloscPieniedzy = p;


}

