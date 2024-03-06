//
// Created by Olek Banasiak on 04.06.2023.
//
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include "Gracz.h"
#include "Plik.h"
#include "GraBlackJack.h"
using namespace std;
Plik plik3;
void GraBlackJack::losowanie(){
    cout << "Losowanie ";
    Sleep(400);
    cout << ". ";
    Sleep(400);
    cout << ". ";
    Sleep(400);
    cout << ". " << endl;
    system("cls");
}

void GraBlackJack::menuBlackJack() {
    cout << "[1]-Graj" << endl;
    cout << "[2]-Zasady gry" << endl;
    cout << "[3]-Wyjscie" << endl;
}
int GraBlackJack::zamianaWartosci(string karta){
    int wynik;

    string subString = karta.substr(0,1);

    if(subString == "A"){
        wynik =11;
    } else if(subString=="K"){
        wynik =10;
    }else if(subString=="Q"){
        wynik =10;
    }else if(subString=="J"){
        wynik =10;
    }else if(karta.substr(0,2)=="10"){
        wynik =10;
    } else{
        wynik = stoi(subString);
    }
    return wynik;
}
void GraBlackJack::menuBlackJackDobieranie() {
    cout <<endl <<"Wybierz opcje" << endl;
    cout << "[1]-Dobierz" << endl;
    cout << "[2]-Pass" << endl;
}
void GraBlackJack::blackJackGra(Gracz &gracz) {
    system("cls");
    bool flaga;
    int wybor;
    do{
        menuBlackJack();
        cin >> wybor;
        switch (wybor) {
            case 1:blackJack(gracz);break;
            case 2:zasadyBlackJack();break;
            case 3: flaga= false;system("cls"); break;
            default: cout << "Podales zla wartosc! "<< endl;
        }
    } while (flaga);
}
void GraBlackJack::losowanieKart(string wylosowaneKarty[], string talia[]){
    srand(time(NULL));
    int los;
    for(int i=0; i<6; i++) {
        los = rand() % 52;
        wylosowaneKarty[i] = talia[los];
        if (wylosowaneKarty[i] == talia[los]) {
            los = rand() % 52;
            wylosowaneKarty[i] = talia[los];
        }
    }
}
void GraBlackJack::zasadyBlackJack() {
    system("cls");
    cout <<"Po wcisnieciu graj nastepuje losowanie 4 kart, dwoch dla gracza i dwoch dla komputera/krupiera z czego jedna \n"
           "karta komputera jest odsonieta. Po wylosowaniu kart gracz staje przed wyborem dobrania karty lub pass. Gdy gracz wybierze \n"
           "dobranie a suma kart krupiera wynosi mniej niz 17, krupier rowniez dobiera karte. Po dobraniu kart, ich suma jest sprawdzana i\n"
           "sumowana. Gdy jeden z graczy ma wiecej niz 21 punktow automatycznie przegrywa, a gdy uzytkownik jak i komputer maja wartosc \n"
           "mniejsza niz 21 to o wyniku gry decyduje wartosc najblizsza 21. Gry jednak uzytkownik wczesniej zdecyduje sie na pass to ilosc\n"
           "kart dla obu graczy wynosi 2 i tak jak przy dobieraniu jest sprawdzana ich wartosc.\n"
           "Wartym do odnotowania jest fakt, ze gdy suma kart jednego z graczy w kazdym stadium gry wynosi 21 to ow gracz automatycznie wygrywa"<< endl<< endl;

}
void GraBlackJack::blackJack(Gracz &gracz) {
    int wybor;

    string kartaKomputera1,  kartaKomputera2, kartaKomputera3, kartaGracza1, kartaGracza2, kartaGracza3;
    string wylosowaneKarty[6];
    string talia[]={"2 Pik", "2 Kier", "2 Trelf", "2 Karo",
                    "3 Pik", "3 Kier", "3 Trelf", "3 Karo",
                    "4 Pik", "4 Kier", "4 Trelf", "4 Karo",
                    "5 Pik", "5 Kier", "5 Trelf", "5 Karo",
                    "6 Pik", "6 Kier", "6 Trelf", "6 Karo",
                    "7 Pik", "7 Kier", "7 Trelf", "7 Karo",
                    "8 Pik", "8 Kier", "8 Trelf", "8 Karo",
                    "9 Pik", "9 Kier", "9 Trelf", "9 Karo",
                    "10 Pik", "10 Kier", "10 Trelf", "10 Karo",
                    "J Pik", "J Kier", "J Trelf", "J Karo",
                    "Q Pik", "Q Kier", "Q Trelf", "Q Karo",
                    "K Pik", "K Kier", "K Trelf", "K Karo",
                    "A Pik", "A Kier", "A Trelf", "A Karo"};
    losowanieKart(wylosowaneKarty, talia);
    kartaKomputera1 = wylosowaneKarty[2];
    kartaKomputera2 = wylosowaneKarty[3];
    kartaKomputera3 = wylosowaneKarty[4];
    kartaGracza1 = wylosowaneKarty[0];
    kartaGracza2 = wylosowaneKarty[1];
    kartaGracza3 = wylosowaneKarty[5];

    int wartosc, koncowaWartosc;
    system("cls");
    gracz.getDane();


    cout << endl << "Ile chcesz postawic: ";
    cin >> wartosc;
    if(wartosc<=0){
        cout << "Nie mozesz tyle postawic"<< endl;
    }else{
    koncowaWartosc = wartosc*2;
    if (gracz.getPieniadz() - wartosc < 0) {
        cout << "Nie masz tyle pieniedzy!!" << endl;
    } else {
        gracz.wezPieniadz(wartosc);

        losowanie();
        cout << "Wylosowane karty komputera:" << endl;
        cout << kartaKomputera1 << "      X " << endl;
        cout << "Twoje wylosowane karty:" << endl;
        cout << kartaGracza1 << "   " << kartaGracza2 << endl;
        int wartoscKartyK1 = zamianaWartosci(kartaKomputera1);
        int wartoscKartyK2 = zamianaWartosci(kartaKomputera2);
        int wartoscKartyG1 = zamianaWartosci(kartaGracza1);
        int wartoscKartyG2 = zamianaWartosci(kartaGracza2);
        int wartoscKartyG3 = zamianaWartosci(kartaGracza3);
        int wartoscKartyK3 = zamianaWartosci(kartaKomputera3);


        if (wartoscKartyK1 + wartoscKartyK2 > 21 && (wartoscKartyK1 == 11 || wartoscKartyK2 == 11)) {
            wartoscKartyK1 = 1;
        } else if (wartoscKartyG1 + wartoscKartyG2 > 21 && (wartoscKartyG1 == 11 || wartoscKartyG2 == 11)) {
            wartoscKartyG1 = 1;
        } else if (wartoscKartyK1 + wartoscKartyK2 == 21) {
            cout << endl << "Komputer wygral!" << endl << "Poniewaz wartosc komputera wyniosla: 21" << endl;
            Sleep(6000);
            system("cls");
        } else if (wartoscKartyG1 + wartoscKartyG2 == 21) {
            cout << endl << "Gracz wygral!" << endl << "Poniewaz wartosc Gracza wyniosla: 21" << endl;;
            gracz.dodajPieniadz(koncowaWartosc);
            plik3.zapisDoPliku(gracz, koncowaWartosc);
            Sleep(6000);
            system("cls");
        } else {


            menuBlackJackDobieranie();
            cin >> wybor;
            switch (wybor) {
                case 1:
                    blackJackDobieranie(gracz, kartaKomputera1, kartaKomputera2, kartaKomputera3, kartaGracza1,
                                        kartaGracza2, kartaGracza3, wartoscKartyK1, wartoscKartyK2, wartoscKartyK3,
                                        wartoscKartyG1, wartoscKartyG2, wartoscKartyG3, koncowaWartosc);
                    break;
                case 2:
                    blackJackPass(gracz, kartaKomputera1, kartaKomputera2, kartaGracza1, kartaGracza2, wartoscKartyK1,
                                  wartoscKartyK2, wartoscKartyG1, wartoscKartyG2, koncowaWartosc);
                    break;
                default:
                    cout << "Podales zla wartosc!";
                    break;
            }

        }
        }
    }

}
void GraBlackJack::blackJackPass(Gracz &gracz, string kartaKomputera1, string kartaKomputera2, string kartaGracza1, string kartaGracza2, int wartoscKartyK1, int wartoscKartyK2,int wartoscKartyG1,int wartoscKartyG2, int koncowaWartosc) {
    system("cls");
    cout << "Wylosowane karty komputera:"<< endl;
    cout << kartaKomputera1<< "   "<< kartaKomputera2<<endl;
    cout << "Twoje wylosowane karty:"<< endl;
    cout << kartaGracza1<< "   "<< kartaGracza2<<endl;


    if(wartoscKartyK1+wartoscKartyK2>wartoscKartyG1+wartoscKartyG2){
        cout << endl<<"Przegrales poniwaz suma kart komputera wyniosla " << wartoscKartyK1+wartoscKartyK2<<" a twoja wyniosla "<<wartoscKartyG1+wartoscKartyG2<<endl;
        Sleep(6000);
        system("cls");
    }else if(wartoscKartyK1+wartoscKartyK2<wartoscKartyG1+wartoscKartyG2){
        cout << endl<<"Wygrales poniwaz suma kart komputera wyniosla " << wartoscKartyK1+wartoscKartyK2<<" a twoja wyniosla "<<wartoscKartyG1+wartoscKartyG2<<endl;
        gracz.dodajPieniadz(koncowaWartosc);
        plik3.zapisDoPliku(gracz, koncowaWartosc);
        Sleep(6000);
        system("cls");
    }else{
        cout << endl<<"Wartosci kart sa takie same, zwrot zakladu"<< endl;
        gracz.dodajPieniadz(koncowaWartosc/2);
        Sleep(4000);
        system("cls");
    }
    gracz.getDane();
    cout <<endl;

}
void GraBlackJack::blackJackDobieranie(Gracz &gracz, string kartaKomputera1, string kartaKomputera2, string kartaKomputera3, string kartaGracza1, string kartaGracza2,string kartaGracza3, int wartoscKartyK1, int wartoscKartyK2,int wartoscKartyK3,int wartoscKartyG1,int wartoscKartyG2,int wartoscKartyG3, int koncowaWartosc) {
    system("cls");
    bool flaga = true;
    if(wartoscKartyK1+wartoscKartyK2<17){
        flaga= false;
        cout << "Wylosowane karty komputera:"<< endl;
        cout << kartaKomputera1<< "   "<< kartaKomputera2 <<"   "<< kartaKomputera3<<endl;
        cout << "Twoje wylosowane karty:" << endl;
        cout << kartaGracza1 << "   " << kartaGracza2 << "   " << kartaGracza3 << endl;
    }else{
        cout << "Wylosowane karty komputera:"<< endl;
        cout << kartaKomputera1<< "   "<< kartaKomputera2 <<"   "<<endl;
        cout << "Twoje wylosowane karty:" << endl;
        cout << kartaGracza1 << "   " << kartaGracza2 << "   " << kartaGracza3 << endl;
    }

    if(!flaga){
        if(wartoscKartyK1+wartoscKartyK2+wartoscKartyK3>21 &&  wartoscKartyK1==11) {
            wartoscKartyK1 = 1;
        }else if(wartoscKartyK1+wartoscKartyK2+wartoscKartyK3>21 &&  wartoscKartyK2==11) {
            wartoscKartyK2 = 1;
        }else if(wartoscKartyK1+wartoscKartyK2+wartoscKartyK3>21 &&  wartoscKartyK3==11) {
            wartoscKartyK3 = 1;
        }
    }
    if(wartoscKartyG1+wartoscKartyG2+wartoscKartyG3>21 &&  wartoscKartyG1==11){
        wartoscKartyG1=1;
    }else if(wartoscKartyG1+wartoscKartyG2+wartoscKartyG3>21 &&  wartoscKartyG2==11){
        wartoscKartyG2=1;
    }else if(wartoscKartyG1+wartoscKartyG2+wartoscKartyG3>21 &&  wartoscKartyG3==11) {
        wartoscKartyG3 = 1;
    }

    bool czyWyjsc=true;
    // flaga = false; czyli komputer ma 3 karty
    while(czyWyjsc) {
        if (!flaga) {
            if(wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3 == 21){
                cout << "Przegrales poniewaz suma kart komutera to 21" << endl;
                czyWyjsc = false;
                Sleep(6000);
                system("cls");
            }else if(wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3 == 21){
                cout << "Wygrales poniewaz twoja suma kart to 21" << endl;
                gracz.dodajPieniadz(koncowaWartosc);
                plik3.zapisDoPliku(gracz, koncowaWartosc);
                czyWyjsc = false;
                Sleep(6000);
                system("cls");
            }else if (wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3 > 21) {
                cout << "Wygrales poniewaz suma kart komutera jest wieksza od 21" << endl;
                gracz.dodajPieniadz(koncowaWartosc);
                plik3.zapisDoPliku(gracz, koncowaWartosc);
                czyWyjsc = false;
                Sleep(6000);
                system("cls");

            } else if (wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3 > 21) {
                cout << "Przegrales poniewaz twoja suma kart jest wieksza od 21" << endl;
                czyWyjsc = false;
                Sleep(6000);
                system("cls");
            } else if (wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3 >
                       wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3) {
                cout << "Przegrales poniewaz suma kart komutera wynosi "<< wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3<< " a twoja "<< wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3<< endl;
                czyWyjsc = false;
                Sleep(6000);
                system("cls");
            } else if (wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3 <
                       wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3) {
                cout << "Wygrales poniewaz suma kart komutera wynosi "<< wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3<< " a twoja "<< wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3<< endl;
                gracz.dodajPieniadz(koncowaWartosc);
                plik3.zapisDoPliku(gracz, koncowaWartosc);
                czyWyjsc = false;
                Sleep(6000);
                system("cls");
            }else{
                cout << "Wartosci kart sa takie same, zwrot zakladu" << endl;
                gracz.dodajPieniadz(koncowaWartosc/2);
                Sleep(6000);
                system("cls");
            }
        }else{
             if(wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3 == 21){
                cout << "Wygrales poniewaz twoja suma kart to 21" << endl;
                 gracz.dodajPieniadz(koncowaWartosc);
                 plik3.zapisDoPliku(gracz, koncowaWartosc);
                czyWyjsc = false;
                 Sleep(6000);
                 system("cls");
            }else if(wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3 > 21){
                 cout << "Przegrales poniewaz twoja suma kart jest wieksza od 21" << endl;
                czyWyjsc = false;
                 Sleep(6000);
                 system("cls");
            }else if (wartoscKartyK1 + wartoscKartyK2 > wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3) {
                 cout << "Przegrales poniewaz suma kart komutera wynosi "<< wartoscKartyK1 + wartoscKartyK2<< " a twoja "<< wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3<< endl;
                czyWyjsc = false;
                 Sleep(6000);
                 system("cls");
            } else if (wartoscKartyK1 + wartoscKartyK2 < wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3) {
                 cout << "Wygrales poniewaz suma kart komutera wynosi "<< wartoscKartyK1 + wartoscKartyK2 + wartoscKartyK3<< " a twoja "<< wartoscKartyG1 + wartoscKartyG2 + wartoscKartyG3<< endl;
                 gracz.dodajPieniadz(koncowaWartosc);
                 plik3.zapisDoPliku(gracz, koncowaWartosc);
                czyWyjsc = false;
                 Sleep(6000);
                 system("cls");
        }else{
                cout << "Wartosci kart sa takie same, zwrot zakladu" << endl;
                 gracz.dodajPieniadz(koncowaWartosc/2);
                 Sleep(6000);
                 system("cls");
            }
        }
    }
    gracz.getDane();
    cout <<endl;





}