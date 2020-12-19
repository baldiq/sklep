#ifndef MANAGERLISTYPRODUKTOW_H
#define MANAGERLISTYPRODUKTOW_H

class ManagerListyProduktow
{
    public:
        ManagerListyProduktow();
        ~ManagerListyProduktow();
        void pokazMenu();
        int dodajProdukt();
        void zarzadzaj();
    private:
        ListaProduktow lista;

};

#endif // MANAGERLISTYPRODUKTOW_H
