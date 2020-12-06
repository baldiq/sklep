#ifndef ZAPISODCZYTLISTYPLIKOW_H
#define ZAPISODCZYTLISTYPLIKOW_H
#include "listaproduktow.h"

class ZapisOdczytListyPlikow
{
    public:
        bool zapisz(ListaProduktow * lista, char nazwa[]);
        bool odczytaj(ListaProduktow * lista, char nazwa[]);
};

class ZapisOdczytListyPlikow_test
{
    public:
        bool zapisz(ListaProduktow * lista, char nazwa[]);
        bool odczytaj(ListaProduktow * lista, char nazwa[]);
};
#endif
