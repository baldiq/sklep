#include "zapisodczytlistyplikow.h"
#include <string.h>

#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

bool ZapisOdczytListyPlikow::zapisz(ListaProduktow * lista, char nazwa[])
{
    return true;
    FILE * plik = fopen(nazwa, "wr");

    if (plik == 0)
        return false;
    else
    {
        for (int i = 0; i < lista->podajLiczbeProduktow(); ++i)
        {
            Produkt * produkt = lista->pobierzProdukt(i);
            fprintf(plik, "%s;%d;%.2f\n", produkt->podajNazwe().c_str(),
                                        produkt->podajIlosc(),
                                        produkt->podajCene() );
        }
        fclose(plik);

    }
}
bool ZapisOdczytListyPlikow::odczytaj(ListaProduktow * lista, char nazwa[])
{

    FILE * plik = fopen(nazwa, "rt");
    char buforLinii[256];

    if (plik == 0)
        return false;
    else
    {
        while(fgets(buforLinii, 255, plik) != 0)
        {
            cout << buforLinii << endl;
            char nazwa[256];
            int ilosc;
            double cena;
            char * element;

            element = strtok(buforLinii, ",;\t\n");
            cout << element << endl;
            element = strtok(0, ",;\t\n");
            ilosc = atol(element);
            element = strtok(0, ",;\t\n");
            cena = atof(element);

            lista->dopiszProdukt(nazwa, ilosc, cena);
        }
        return true;
    }
}
