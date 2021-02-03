#include "managerlistyproduktow.h"
#include <iostream>
#include "zapisodczytlistyplikow.h"
#include "widoklistyproduktow.h"

using namespace std;

ManagerListyProduktow::ManagerListyProduktow()
{
    cout << "Zarzadzam lista produktow" << endl;
}

ManagerListyProduktow::~ManagerListyProduktow()
{
    cout << "Nacisnij enter by zakonczyc...";
    cin.ignore();
    cin.get();
}
void ManagerListyProduktow::zapiszListe()
{
    ZapisOdczytListyPlikow zapisOdczyt;
    zapisOdczyt.zapisz(&lista, "produkty.txt");
}

void ManagerListyProduktow::pokazMenu()
{
    cout << "Dostepne opcje\n\t1. Pokaz produkty\n\t2. Dodaj produkt\n\t";
    cout << "\n\t 0. Koniec";
    cout << endl << " >> ";
}

void ManagerListyProduktow::pokazListeProduktow()
{
    ZapisOdczytListyPlikow zapisOdczyt;
    zapisOdczyt.odczytaj(&lista, "produkty.txt");
//    WidokListyProduktow widok;
//    widok.pokazProdukty(&lista);
}

bool ManagerListyProduktow::dodajProdukt()
{
    string nazwa;
    int ilosc;
    double cena;


    cout << "\nPodaj nazwe produktu: ";
    cin >> nazwa;
    cout << "\nPodaj ilosc produktu: ";
    cin >> ilosc;
    cout << "\nPodaj cene produktu: ";
    cin >> cena;

    return lista.dopiszProdukt(nazwa, ilosc, cena);
}

void ManagerListyProduktow::zarzadzaj()
{
    const int KONIEC = 0;
    int idOpcji = 10;

    do
    {
        pokazMenu();
        cin >> idOpcji;

        switch(idOpcji)
        {
        case 1:
            pokazListeProduktow();
            break;
        case 2:
            dodajProdukt();
            break;
        case 3:
            ;
            break;
        }
    }
    while (idOpcji != KONIEC);
}

