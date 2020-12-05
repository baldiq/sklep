#include <string>

#ifndef LISTAPRODUKTOW_H
#define LISTAPRODUKTOW_H

extern const int MAKS_LB_PRODUKTOW = 100;

class Produkt
{
    public:
        Produkt(std::string nazwa, int ilosc, double cena);
        void ustawNazwe(std::string n);
        std::string podajNazwe();
        void ustawIlosc(int il);
        int podajIlosc();
        void ustawCene(double c);
        double podajCene();
    protected:
        std::string nazwa;
        int ilosc;
        double cena;
};

class ListaProduktow
{
    public:
        ListaProduktow();
        bool dopiszProdukt(std::string nazwa, int ilosc, double cena);
        bool dopiszProdukt(Produkt * produkt);
        Produkt * pobierzProdukt(int nrProduktu);
        int podajLiczbeProduktow();
    protected:
        int liczbaProduktow;
        Produkt * produkty[MAKS_LB_PRODUKTOW];
};



#endif // LISTAPRODUKTOW_H
