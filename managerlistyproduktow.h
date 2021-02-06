#ifndef MANAGERLISTYPRODUKTOW_H
#define MANAGERLISTYPRODUKTOW_H

#include "listaproduktow.h"
#include "zapisodczytlistyplikow.h"
#include "widoklistyproduktow.h"

class ManagerListyProduktow
{
    public:
        ManagerListyProduktow();
        ~ManagerListyProduktow();
        void pokazMenu();
        void pokazListeProduktow();
        int dodajProdukt();
        int edytujProdukt();
        void zarzadzaj();
        void usunProdukt();
    protected:
        ListaProduktow lista;
        ZapisOdczytListyPlikow zapisOdczyt;
        WidokListyProduktow widokListy;
        WidokProduktu widokProduktu;

};

#endif // MANAGERLISTYPRODUKTOW_H
