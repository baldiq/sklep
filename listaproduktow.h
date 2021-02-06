#include <string>
#include "produkty.h"

#ifndef LISTAPRODUKTOW_H
#define LISTAPRODUKTOW_H

class ListaProduktow
{
    public:
        ListaProduktow();
        ~ListaProduktow();
        bool dopiszProdukt(std::string nazwa, int ilosc, double cena);
        bool dopiszProdukt(Produkt * produkt);
        Produkt * pobierzProdukt(int nrProduktu);
        int podajLiczbeProduktow();
        bool usunProdukt(int nrProduktu);
    protected:
        int liczbaProduktow;
        Produkt * produkty[MAKS_LB_PRODUKTOW];
        bool dodajDoListy(Produkt * produkt);
};



#endif // LISTAPRODUKTOW_H

