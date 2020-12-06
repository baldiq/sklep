#include <string>

#ifndef PRODUKTY_H
#define PRODUKTY_H

const int MAKS_LB_PRODUKTOW = 100;

class Produkt
{
    public:
        Produkt(std::string nazwa, int ilosc, double cena);
        ~Produkt();
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


#endif // PRODUKTY_H
