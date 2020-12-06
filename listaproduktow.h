#include <string>
#include "produkty.h"

#ifndef LISTAPRODUKTOW_H
#define LISTAPRODUKTOW_H

// Klasa przechowuje wskaüniki do produktow alokowanych dynamicznie
// z wykorzystaniem operatora new, w momencie usuwania obiektu listy
// produktow, usuwane sπ rowniez obiekty samych produktow,
// co wykonuje destruktur uzywajac operatora delete.

class ListaProduktow
{
    public:
        ListaProduktow();
        ~ListaProduktow();
        bool dopiszProdukt(std::string nazwa, int ilosc, double cena);
        bool dopiszProdukt(Produkt * produkt);

        Produkt * pobierzProdukt(int nrProduktu);
        int podajLiczbeProduktow();
    protected:
        int liczbaProduktow;
        Produkt * produkty[MAKS_LB_PRODUKTOW];
        bool dodajDoListy(Produkt * produkt);
};



#endif // LISTAPRODUKTOW_H

