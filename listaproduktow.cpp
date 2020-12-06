#include "listaproduktow.h"


// METODY PRODUKT


using namespace std;

Produkt::Produkt(string nazwa, int ilosc, double cena)
{
    if(nazwa.empty())
        Produkt::ustawNazwe("Nieznany");
    if(ilosc < 0)
        Produkt::ustawIlosc(0);
    if(cena < 0)
        Produkt::ustawCene(0);
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


// METODY LISTA PRODUKTOW


ListaProduktow::ListaProduktow() : liczbaProduktow(0)
{
}

bool ListaProduktow::dopiszProdukt(string nazwa, int ilosc, double cena)
{
    if(liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
    {
        produkty[liczbaProduktow++] = new Produkt(nazwa, ilosc, cena);
        return true;
    }
    else
        return false;
}

bool ListaProduktow::dopiszProdukt(Produkt * produkt)
{
    if(liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
    {
        produkty[liczbaProduktow++] = produkt;
        return true;
    }
    else
        return false;
}
ListaProduktow::Produkt * pobierzProdukt(int nrProduktu)
{
    if(nrProduktu < liczbaProduktow && nrProduktu >= 0)
    {
        return produkty[nrProduktu];
    }
    else
    {
        return 0;
    }
}

int ListaProduktow::podajLiczbeProduktow()
{
    return liczbaProduktow;
}
