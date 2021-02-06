#ifndef WIDOKLISTYPRODUKTOW_H
#define WIDOKLISTYPRODUKTOW_H
#include "listaproduktow.h"
#include "produkty.h"

class WidokListyProduktow
{
    public:
        void pokazProdukty(ListaProduktow *lista);
        void pokazProduktyWTabeli(ListaProduktow *lista);
};


class WidokProduktu
{
    public:
        static void pokazProdukt(Produkt *p);
        static void pokazProduktWLinii(Produkt *p);
};

#endif // WIDOKLISTYPRODUKTOW_H_INCLUDED
