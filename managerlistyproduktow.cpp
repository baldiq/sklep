#include "managerlistyproduktow.h"
#include <iostream>
#include "zapisodczytlistyplikow.h"
#include "widoklistyproduktow.h"

using namespace std;

ManagerListyProduktow::ManagerListyProduktow()
{
    cout << "Zarzadzam lista produktow" << endl;
    ZapisOdczytListyPlikow zapisOdczyt;
    zapisOdczyt.odczytaj(&lista, "produkty.txt");
}

ManagerListyProduktow::~ManagerListyProduktow()
{

    ZapisOdczytListyPlikow zapisOdczyt;
    zapisOdczyt.zapisz(&lista, "produkty.txt");
    cout << "Nacisnij enter by zakonczyc...";
    cin.ignore();
    cin.get();
}

void ManagerListyProduktow::pokazMenu()
{
    cout << "Dostepne opcje\n\t1. Pokaz produkty\n\t2. Dodaj produkt\n\t";
    cout << "\n\t 0. Koniec";
    cout << endl << " >> ";
}

void ManagerListyProduktow::pokazListeProduktow()
{
    WidokListyProduktow widok;
    widok.pokazProduktyWTabeli(&lista);
}

int ManagerListyProduktow::dodajProdukt(string nazwa, int ilosc, double cena)
{
    ListaProduktow lista;
    return lista.dopiszProdukt(nazwa, ilosc, cena);
}

void ManagerListyProduktow::zarzadzaj()
{
    const int KONIEC = 0;
    int idOpcji = 10;
    string nazwa;
    int ilosc;
    double cena;

    do
    {
        pokazMenu();
        cin >> idOpcji;

        switch(idOpcji)
        {
            case 1: pokazListeProduktow();
                break;
            case 2:
                cout << "\nPodaj nazwe produktu: "; cin >> nazwa;
                cout << "\nPodaj ilosc produktu: "; cin >> ilosc;
                cout << "\nPodaj cene produktu: "; cin >> cena;
                dodajProdukt(nazwa, ilosc, cena);
                break;
            case 3: ;
                break;
        }
    }
    while (idOpcji != KONIEC);
}

