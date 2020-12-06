#include "produkty.h"

using namespace std;

// METODY PRODUKT


Produkt::Produkt(string nazwa, int ilosc, double cena)
{
    if(nazwa.empty())
        Produkt::ustawNazwe("Nieznany");
    if(ilosc < 0)
        Produkt::ustawIlosc(0);
    if(cena < 0)
        Produkt::ustawCene(0);
}

Produkt::~Produkt()
{

}
void Produkt::ustawNazwe(string n)
{
    nazwa = n;
}

string Produkt::podajNazwe()
{
    return nazwa;
}

void Produkt::ustawIlosc(int il)
{
    ilosc = il;
}

int Produkt::podajIlosc()
{
    return ilosc;
}

void Produkt::ustawCene(double c)
{
    cena = c;
}

double Produkt::podajCene()
{
    return cena;
}

