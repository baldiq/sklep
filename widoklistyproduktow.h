#ifndef WIDOKLISTYPRODUKTOW_H
#define WIDOKLISTYPRODUKTOW_H
#include "listaproduktow.h"
#include "widokproduktu.h"

class WidokListyProduktow
{
    public:
        void pokazProdukty(ListaProduktow *lista, char naglowek[] = "");
        void pokazProduktyWTabeli(ListaProduktow *lista, char naglowek[] = "");
    protected:
        ListaProduktow lista;
        WidokProduktu widok;
};

#endif // WIDOKLISTYPRODUKTOW_H_INCLUDED
