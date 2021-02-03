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
        void zapiszListe();
        bool dodajProdukt();
        void zarzadzaj();
    private:
        ListaProduktow lista;

};

#endif // MANAGERLISTYPRODUKTOW_H
