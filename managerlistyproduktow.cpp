#include "managerlistyproduktow.h"
#include <iostream>

using namespace std;

ManagerListyProduktow::ManagerListyProduktow()
{
    cout << "Zarzadzam lista produktow" << endl;
}

ManagerListyProduktow::~ManagerListyProduktow()
{
    zapisOdczyt.zapisz(&lista, "produkty.txt");
    cout << "Nacisnij enter by zakonczyc...";
    cin.ignore();
    cin.get();
}

void ManagerListyProduktow::pokazMenu()
{
    cout << "Dostepne opcje\n\t1. Dodaj produkt\n\t2. Pokaz produkty\n\t3. Edytuj produkt\n\t4. Usun produkty\n\t";
    cout << "\n\t 99. Koniec";
    cout << endl << " >> ";
}

void ManagerListyProduktow::pokazListeProduktow()
{
    widokListy.pokazProduktyWTabeli(&lista);
}


int ManagerListyProduktow::dodajProdukt()
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

    lista.dopiszProdukt(nazwa, ilosc, cena);
}

int ManagerListyProduktow::edytujProdukt()
{
    int nrProduktu;
    cout << "Ktory produkt chcesz edytowac?"; cin >> nrProduktu;
    widokListy.pokazProdukty(&lista);

    Produkt * produkt = lista.pobierzProdukt(nrProduktu-1);
    lista.usunProdukt(nrProduktu);
    this->dodajProdukt();
}

void ManagerListyProduktow::usunProdukt()
{
    int nrProduktu;
    cout << "Wybierz produkt, maksymalny dostepny produkt to: " << lista.podajLiczbeProduktow() << ". "; cin >> nrProduktu;

    Produkt * produkt = lista.pobierzProdukt(nrProduktu);
    lista.usunProdukt(nrProduktu);
}

void ManagerListyProduktow::zarzadzaj()
{
    const int KONIEC = 99;
    int idOpcji = 10;

    do
    {
        pokazMenu();
        cin >> idOpcji;

        switch(idOpcji)
        {
        case 1:
            dodajProdukt();
            break;
        case 2:
            pokazListeProduktow();
            break;
        case 3:
            edytujProdukt();
            break;
        case 4:
            usunProdukt();
            break;
        }
    }
    while (idOpcji != KONIEC);
}

