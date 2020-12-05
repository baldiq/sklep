#include <iostream>
#include <cstdlib>
#include "listaproduktow.h"



using namespace std;

// 1. Poprawki w komentarzach
// 2. Ręczna refaktoryzacja kodu, polegająca na
// przekształceniu programu w wersję wielomodułową
// tzn.
// - tworzymy moduł listaproduktow.h i listaproduktow.cpp
// - do tego modułu przenosimy klasy Produkt i ListaProduktow.
// Wszystkie funkcje zdefiniowane w ciele klasy zmienamy
// na funkcje zdefiniowane w pliku listaproduktow.cpp
// W ciele klasy pozostawiamy tylko deklaracje funkcji składowych (prototypy)
// Tworzymy osobne program główny, zawierający funkcję main.
// W funkcji zostawiamy na razie kod testujący klasę Produkt i ListaProduktow
// Podobno czegoś brakuje i trzeba uzupełnić.
// EDIT: brakuje destruktorow i usuwania obiektow
//
//
//class Produkt
//{
//    public:
//        Produkt(string nazwa = "", int ilosc = 0, double cena = 0)
//        : nazwa(nazwa), ilosc(ilosc), cena(cena)
//        {
//            if(nazwa.empty())
//                Produkt::ustawNazwe("Nieznany");
//            if(ilosc < 0)
//                Produkt::ustawIlosc(0);
//            if(cena < 0)
//                Produkt::ustawCene(0);
//        }
//
//        // Settery i gettery pol prywatnych
//
//        void ustawNazwe(string n)
//        {
//            nazwa = n;
//        }
//
//        string podajNazwe()
//        {
//            return nazwa;
//        }
//
//        void ustawIlosc(int il)
//        {
//            ilosc = il;
//        }
//
//        int podajIlosc()
//        {
//            return ilosc;
//        }
//
//        void ustawCene(double c)
//        {
//            cena = c;
//        }
//
//        double podajCene()
//        {
//            return cena;
//        }
//
//    private:
//        string nazwa;
//        int ilosc;
//        double cena;
//};
//
//class ListaProduktow
//{
//    public:
//        ListaProduktow() : liczbaProduktow(0)
//        {
//        }
//
//        bool dopiszProdukt(string nazwa, int ilosc, double cena)
//        {
//            if(liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
//            {
//                produkty[liczbaProduktow++] = new Produkt(nazwa, ilosc, cena);
//                return true;
//            }
//            else
//                return false;
//        }
//
//        bool dopiszProdukt(Produkt * produkt)
//        {
//            if(liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
//            {
//                produkty[liczbaProduktow++] = produkt;
//                return true;
//            }
//            else
//                return false;
//        }
//        Produkt * pobierzProdukt(int nrProduktu)
//        {
//            if(nrProduktu < liczbaProduktow && nrProduktu >= 0)
//            {
//                return produkty[nrProduktu];
//            }
//            else
//            {
//                return 0;
//            }
//        }
//
//        int podajLiczbeProduktow()
//        {
//            return liczbaProduktow;
//        }
//    private:
//        int liczbaProduktow;
//        Produkt * produkty[MAKS_LB_PRODUKTOW];
//};

int main()
{
    ListaProduktow lista;

    lista.dopiszProdukt("Dysk SSD", 20, 400.0);
    lista.dopiszProdukt(new Produkt("Pendrive", 30, 40.0));
    lista.dopiszProdukt("Monitor", 40, 800.0);
    lista.dopiszProdukt(new Produkt("Sluchawki", 50, 200.0));


    for (int i = 0; i < lista.podajLiczbeProduktow(); ++i)
    {
        Produkt * wskRoboczy = lista.pobierzProdukt(i);
        cout << endl << wskRoboczy->podajNazwe();
        cout << endl << wskRoboczy->podajIlosc();
        cout << endl << wskRoboczy->podajCene() << endl;
    }


    return EXIT_SUCCESS;
}
