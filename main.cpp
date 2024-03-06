#include <iostream>
#include <windows.h>
#include "Gracz.h"
#include "GraJednoreki.h"
#include "GraRuletka.h"
#include "GraBlackJack.h"
#include "Plik.h"
using namespace std;

    Gracz gracz;
    GraJednoreki graJ;
    GraRuletka graR;
    GraBlackJack graB;
    Plik plik;


void menu(){

    cout << "[1]- BlackJack"<< endl;
    cout << "[2]- Jednoreki bandyta"<< endl;
    cout << "[3]- Ruletka"<< endl;
    cout << "[4]- Top 100 wygranych"<< endl;
    cout << "[5]- Wyjscie"<< endl;


}
void poczatek(){
    cout << "-------------------------------------------------------------"<< endl;
    cout << "$$\\   $$\\  $$$$$$\\   $$$$$$\\ $$\\     $$\\ $$\\   $$\\  $$$$$$\\  \n"
            "$$ | $$  |$$  __$$\\ $$  __$$\\\\$$\\   $$  |$$$\\  $$ |$$  __$$\\ \n"
            "$$ |$$  / $$ /  $$ |$$ /  \\__|\\$$\\ $$  / $$$$\\ $$ |$$ /  $$ |\n"
            "$$$$$  /  $$$$$$$$ |\\$$$$$$\\   \\$$$$  /  $$ $$\\$$ |$$ |  $$ |\n"
            "$$  $$<   $$  __$$ | \\____$$\\   \\$$  /   $$ \\$$$$ |$$ |  $$ |\n"
            "$$ |\\$$\\  $$ |  $$ |$$\\   $$ |   $$ |    $$ |\\$$$ |$$ |  $$ |\n"
            "$$ | \\$$\\ $$ |  $$ |\\$$$$$$  |   $$ |    $$ | \\$$ | $$$$$$  |\n"
            "\\__|  \\__|\\__|  \\__| \\______/    \\__|    \\__|  \\__| \\______/ "
                                                                        <<endl;
    cout << "-------------------------------------------------------------"<< endl;
    cout << "Ladowanie";
    Sleep(400);
    cout<< ". ";
    Sleep(400);
    cout<< ". ";
    Sleep(400);
    cout<< ". ";
    Sleep(700);
    system("cls");
}
void uzytkownik(){

    gracz.setDane();
    system("cls");
    gracz.getDane();
    cout << endl;
}

int main() {



    poczatek();
    bool flaga = true;
    int wybor;
    uzytkownik();




    do{
        menu();
        cout << "Wybierz opcje:";
        cin >> wybor;

        switch(wybor) {
            case 1: graB.blackJackGra(gracz);
                break;
            case 2: graJ.jednorekiBandytaGra(gracz);
                break;
            case 3: graR.ruletkaGra(gracz);
                break;
            case 4: plik.sortowanie();
                break;
            case 5:
                flaga = false;
                break;

        }
    } while (flaga);





}
