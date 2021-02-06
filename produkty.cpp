#include "produkty.h"

using namespace std;

// METODY PRODUKT


Produkt::Produkt(string nazwa, int ilosc, double cena)
{
    if(nazwa.empty())
        Produkt::ustawNazwe("Nieznany");
    else
        Produkt::ustawNazwe(nazwa);
    if(ilosc < 0)
        Produkt::ustawIlosc(0);
    else
        Produkt::ustawIlosc(ilosc);
    if(cena < 0)
        Produkt::ustawCene(0);
    else
        Produkt::ustawCene(cena);
}

Produkt::~Produkt()
{

}
void Produkt::ustawNazwe(string n)
{
    this->nazwa = n;
}

string Produkt::podajNazwe()
{
    return nazwa;
}

void Produkt::ustawIlosc(int il)
{
    this->ilosc = il;
}

int Produkt::podajIlosc()
{
    return ilosc;
}

void Produkt::ustawCene(double c)
{
    this->cena = c;
}

double Produkt::podajCene()
{
    return cena;
}

