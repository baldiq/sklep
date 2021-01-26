#ifndef MANAGERLISTYPRODUKTOW_H
#define MANAGERLISTYPRODUKTOW_H

#include "listaproduktow.h"

class ManagerListyProduktow
{
    public:
        ManagerListyProduktow();
        ~ManagerListyProduktow();
        void pokazMenu();
        void pokazListeProduktow();
        int dodajProdukt(std::string nazwa, int ilosc, double cena);
        void zarzadzaj();
    private:
        ListaProduktow lista;

};

#endif // MANAGERLISTYPRODUKTOW_H
