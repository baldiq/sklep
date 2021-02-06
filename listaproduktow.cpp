#include "listaproduktow.h"

using namespace std;


ListaProduktow::ListaProduktow() : liczbaProduktow(0)
{
}

ListaProduktow::~ListaProduktow()
{

    for(int i = 0; i < liczbaProduktow; ++i)
        delete produkty[i];
}

bool ListaProduktow::dopiszProdukt(string nazwa, int ilosc, double cena)
{

    Produkt * produkt = new Produkt(nazwa, ilosc, cena);
    return ListaProduktow::dodajDoListy(produkt);
}

bool ListaProduktow::dopiszProdukt(Produkt * produkt)
{
    return ListaProduktow::dodajDoListy(produkt);
}

bool ListaProduktow::dodajDoListy(Produkt * produkt)
{
    if(liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
    {
        produkty[liczbaProduktow++] = produkt;
        return true;
    }
    else
        return false;
}

Produkt * ListaProduktow::pobierzProdukt(int nrProduktu)
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

bool ListaProduktow::usunProdukt(int nrProduktu)
{
    delete produkty[nrProduktu];
    liczbaProduktow -= 1;
}
