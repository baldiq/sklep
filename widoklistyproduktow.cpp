#include <iostream>
#include "widoklistyproduktow.h"
#include "listaproduktow.h"
#include "widokproduktu.h"

using namespace std;

void WidokListyProduktow::pokazProdukty(ListaProduktow *lista, char naglowek[])
{
    if(lista -> podajLiczbeProduktow() <= 0)
        return;
    cout << endl << naglowek << endl;
    for (int i =0; i < lista->podajLiczbeProduktow(); i++)
        WidokProduktu::pokazProdukt(lista->pobierzProdukt(i));
}

void WidokListyProduktow::pokazProduktyWTabeli(ListaProduktow *lista, char naglowek[])
{
    if(lista->podajLiczbeProduktow() <= 0)
        return;
    cout << endl << naglowek << endl;
    cout << "Nazwa Ilosc Cena" << endl;
    for(int i = 0; i < lista->podajLiczbeProduktow(); i++)
        WidokProduktu::pokazProduktWLinii(lista->pobierzProdukt(i));
}

