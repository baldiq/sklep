#include "listaproduktow.h"
#include "produkty.h"


using namespace std;


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
