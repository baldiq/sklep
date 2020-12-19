#include "widokproduktu.h"
#include "produkty.h"

static void WidokProduktu::pokazProdukt(Produkty *p)
{
    cout << endl << "Nazwa: " << p->nazwa;
    cout << endl << "Ilosc: " << p->ilosc;
    cout << endl << "Cena: "  << p->cena;
}
