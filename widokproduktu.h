#ifndef WIDOKPRODUKTU_H
#define WIDOKPRODUKTU_H
#include "produkty.h"

class WidokProduktu
{
    public:
        static void pokazProdukt(Produkt *p);
        static void pokazProduktWLinii(Produkt *p);
    protected:
        Produkt p;
};

#endif WIDOKPRODUKTU_H
