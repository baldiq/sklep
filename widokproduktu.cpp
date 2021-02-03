#include "widokproduktu.h"

#include <iostream>

using namespace std;

void WidokProduktu::pokazProdukt(Produkt *p)
{
    cout << endl << "Nazwa: " << p->podajNazwe();
    cout << endl << "Ilosc: " << p->podajIlosc();
    cout << endl << "Cena: "  << p->podajCene();
}
void WidokProduktu::pokazProduktWLinii(Produkt *p)
{
    cout << p->podajNazwe() << ' ';
    cout << p->podajIlosc() << ' ';
    cout << p->podajCene() << ' ' << endl;
}
