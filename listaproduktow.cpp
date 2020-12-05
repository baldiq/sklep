#include "listaproduktow.h"


// METODY PRODUKT


Produkt::Produkt(nazwa, ilosc, cena)
{
    if(nazwa.empty())
        Produkt::ustawNazwe("Nieznany");
    if(ilosc < 0)
        Produkt::ustawIlosc(0);
    if(cena < 0)
        Produkt::ustawCene(0);
}

Produkt::ustawNazwe(string n)
{
    nazwa = n;
}

Produkt::podajNazwe()
{
    return nazwa;
}

Produkt::ustawIlosc(int il)
{
    ilosc = il;
}

Produkt::podajIlosc()
{
    return ilosc;
}

Produkt::ustawCene(double c)
{
    cena = c;
}

Produkt::podajCene()
{
    return cena;
}



// METODY LISTA PRODUKTOW


  ListaProduktow::ListaProduktow() : liczbaProduktow(0)
{
}

ListaProduktow::dopiszProdukt(string nazwa, int ilosc, double cena)
{
    if(liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
    {
        produkty[liczbaProduktow++] = new Produkt(nazwa, ilosc, cena);
        return true;
    }
    else
        return false;
}

ListaProduktow::dopiszProdukt(Produkt * produkt)
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

ListaProduktow::podajLiczbeProduktow()
{
    return liczbaProduktow;
}

