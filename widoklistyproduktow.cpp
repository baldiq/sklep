#include <iostream>
#include "widoklistyproduktow.h"


using namespace std;

void WidokListyProduktow::pokazProdukty(ListaProduktow *lista)
{
    if(lista -> podajLiczbeProduktow() <= 0)
        return;
    for (int i =0; i < lista->podajLiczbeProduktow(); i++)
        WidokProduktu::pokazProdukt(lista->pobierzProdukt(i));
}

void WidokListyProduktow::pokazProduktyWTabeli(ListaProduktow *lista)
{
    if(lista->podajLiczbeProduktow() <= 0)
        return;
    cout << "Nazwa Ilosc Cena" << endl;
    for(int i = 0; i < lista->podajLiczbeProduktow(); i++)
        WidokProduktu::pokazProduktWLinii(lista->pobierzProdukt(i));
}


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
