#include "managerlistyproduktow.h"
#include <iostream>

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
    zapisOdczyt.zapisz(&lista, "produkty.txt");
}

void ManagerListyProduktow::pokazMenu()
{
    cout << "Dostepne opcje\n\t1. Pokaz produkty\n\t2. Dodaj produkt\n\t3. Edytuj produkt\n\t4. Zapisz liste produktow\n\t";
    cout << "\n\t 0. Koniec";
    cout << endl << " >> ";
}

void ManagerListyProduktow::pokazListeProduktow()
{

    zapisOdczyt.odczytaj(&lista, "produkty.txt");
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
    cout << "Ktory produkt chcesz edytowac? "; cin >> nrProduktu;

    if (nrProduktu > lista.podajLiczbeProduktow())
    {
        cout << "Jest " << lista.podajLiczbeProduktow() << " produktow, a Ty wybrales produkt " << nrProduktu << "! Podaj inny numer";
        edytujProdukt();
    }



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
            edytujProdukt();
            break;
        case 4:
            zapiszListe();
            break;
        }
    }
    while (idOpcji != KONIEC);
}

