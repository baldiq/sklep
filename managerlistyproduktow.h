#ifndef MANAGERLISTYPRODUKTOW_H
#define MANAGERLISTYPRODUKTOW_H

#include "listaproduktow.h"
#include "zapisodczytlistyplikow.h"

class ManagerListyProduktow
{
    public:
        ManagerListyProduktow();
        ~ManagerListyProduktow();
        void pokazMenu();
        void pokazListeProduktow();
        void zapiszListe();
        int dodajProdukt();
        int edytujProdukt();
        void zarzadzaj();
    protected:
        ListaProduktow lista;
        ZapisOdczytListyPlikow zapisOdczyt;

};

#endif // MANAGERLISTYPRODUKTOW_H
