#ifndef WIDOKLISTYPRODUKTOW_H_INCLUDED
#define WIDOKLISTYPRODUKTOW_H_INCLUDED
#include "listaproduktow.h"

class WidokListyProduktow
{
public:
    void pokazProdukty(ListaProduktow *lista, char naglowek[] = "");
    void pokazProduktyWTabeli(ListaProduktow *lista, char naglowek[] = "");
};
#endif // WIDOKLISTYPRODUKTOW_H_INCLUDED
