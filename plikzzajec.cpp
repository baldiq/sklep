#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
 
// Robimy:
// 1. Dodawanie produktów do listy, implementacja funkcji dodajProdukt
// 2. Formatujemy ładnie tabelę przegądu produktów, wyrównanie w kolumnach
 
const int MAKS_LB_PRODUKTOW = 20;
class Produkt
{
  public:
    Produkt(string nazwa = "", int ilosc = 0, double cena = 0)
    : nazwa(nazwa), ilosc(ilosc), cena(cena)
    {
       if(nazwa.empty())
         Produkt::nazwa = "Nieznany produkt";
       if(ilosc < 0)
         Produkt::ilosc = 0;
       if(cena < 0)
         Produkt::cena = 0;
    }
  public:
    string nazwa;
    int ilosc;
    double cena;
};
 
// Klasa przechowuje wskaźniki do produktów alokowanych dynamicznie
// z wykorzystaniem operatora new. W momencie usuwania obiektu listy
// produktów, usuwane są również obiekty samych produktów, co wykonuje
// destruktor używając operatora delete.
class ListaProduktow
{
  public:
    ListaProduktow() : liczbaProduktow(0)
    {
    }
 
    ~ListaProduktow()
    {
       for(int i = 0 ; i < liczbaProduktow; ++i)
         delete produkty[i];
    }
 
    bool dopiszProdukt(string nazwa, int ilosc, double cena)
    {
      return dodajDoListy(new Produkt(nazwa, ilosc, cena));
    }
 
    bool dopiszProdukt(Produkt * produkt)
    {
      return dodajDoListy(produkt);
    }
 
    Produkt * pobierzProdukt(int nrProduktu)
    {
      if(nrProduktu < liczbaProduktow && nrProduktu >= 0)
        return produkty[nrProduktu];
      else
        return 0;
    }
 
    int podajLiczbeProduktow()
    {
      return liczbaProduktow;
    }
 
  private:
    int liczbaProduktow;
    Produkt * produkty[MAKS_LB_PRODUKTOW];
 
    bool dodajDoListy(Produkt * produkt)
    {
      if(produkt != 0 && liczbaProduktow < MAKS_LB_PRODUKTOW - 1)
      {
         produkty[liczbaProduktow++] = produkt;
         return true;
      }
      else
        return false;
    }
};
 
class ZapisOdczytListyProduktowSTDIO
{
  public:
    bool zapisz(ListaProduktow *lista, char nazwa[])
    {
      FILE * plik = fopen(nazwa, "wt");
 
      if(plik == 0)
        return false;
      else
      {
        for(int i = 0; i < lista->podajLiczbeProduktow(); ++i)
        {
          Produkt *produkt = lista->pobierzProdukt(i);
          fprintf(plik, "%s;%d;%.2f\n", produkt->nazwa.c_str(),
                                        produkt->ilosc,
                                        produkt->cena);
        }
        fclose(plik);
        return true;
      }
    }
    bool odczytaj(ListaProduktow *lista, char nazwa[])
    {
      FILE * plik = fopen(nazwa, "rt");
      char buforLinii[256];
 
      if(plik == 0)
        return false;
      else
      {
        while(fgets(buforLinii, 255, plik) != 0)
        {
          char nazwa[256];
          int ilosc;
          double cena;
          char * element;
 
          element = strtok(buforLinii, ",;\t\n");
          strcpy(nazwa, element);
          element = strtok(0, ",;\t\n");
          ilosc = atoi(element);
          element = strtok(0, ",;\t\n");
          cena = atof(element);
          lista->dopiszProdukt(nazwa, ilosc, cena);
        }
        return true;
      }
    }
};
 
class ZapisOdczytListyProduktowIOStream
{
  public:
    bool zapisz(ListaProduktow *lista, char nazwa[])
    {
      ofstream plik(nazwa, ofstream::out | std::ofstream::trunc);
      if(!plik.is_open())
        return false;
      else
      {
        for(int i = 0; i < lista->podajLiczbeProduktow(); ++i)
        {
          Produkt *produkt = lista->pobierzProdukt(i);
          plik << produkt->nazwa.c_str() << ';';
          plik << produkt->ilosc << ';';
          plik << produkt->cena << '\n';
        }
        plik.close();
        return true;
      }
    }
    bool odczytaj(ListaProduktow *lista, char nazwa[])
    {
      ifstream plik(nazwa);
      if(!plik.is_open())
        return false;
      else
      {
        char buforLinii[256];
        plik.getline(buforLinii, 255);
        while(plik.good())
        {
          char nazwa[256];
          int ilosc;
          double cena;
          char * element;
 
          element = strtok(buforLinii, ",;\t\n");
          strcpy(nazwa, element);
          element = strtok(0, ",;\t\n");
          ilosc = atoi(element);
          element = strtok(0, ",;\t\n");
          cena = atof(element);
          lista->dopiszProdukt(nazwa, ilosc, cena);
 
          plik.getline(buforLinii, 256);
        }
        plik.close();
        return true;
      }
    }
};
 
class WidokProduktu
{
   public:
     static void pokazProdukt(Produkt *p)
     {
       cout << endl << "Nazwa: " << p->nazwa;
       cout << endl << "Ilosc: " << p->ilosc;
       cout << endl << " Cena: " << p->cena;
     }
     static void pokazProduktWLinii(Produkt *p)
     {
       cout << p->nazwa << ' ';
       cout << p->ilosc << ' ';
       cout << p->cena  << ' ' << endl;
     }
};
 
class WidokListyProduktow
{
   public:
     void pokazProdukty(ListaProduktow *lista, char naglowek[] = "")
     {
        if(lista->podajLiczbeProduktow() <= 0)
          return;
        cout << endl << naglowek << endl;
        for(int i = 0; i < lista->podajLiczbeProduktow(); ++i)
          WidokProduktu::pokazProdukt(lista->pobierzProdukt(i));
     }
 
     void pokazProduktyWTabeli(ListaProduktow *lista, char naglowek[] = "")
     {
        if(lista->podajLiczbeProduktow() <= 0)
          return;
        cout << endl << naglowek << endl;
        cout << "Nazwa Ilosc Cena" << endl;
        for(int i = 0; i < lista->podajLiczbeProduktow(); ++i)
          WidokProduktu::pokazProduktWLinii(lista->pobierzProdukt(i));
     }
};
 
class ManagerListyProduktow
{
   public:
     ManagerListyProduktow()
     {
       cout << "Zarzadzam lista produktow" << endl;
 
       zapisOdczyt.odczytaj(&lista, "produkty.txt");
     }
     ~ManagerListyProduktow()
     {
       zapisOdczyt.zapisz(&lista, "produkty.txt");
 
       cout << endl << "Nacisnij Enter by zakonczyc...";
       cin.ignore();
       cin.get();
     }
 
     void pokazMenu()
     {
       cout << "\n\nDostepne operacje:\n 1. Pokaz produkty\n 2. Dodaj produkt";
       cout << "\n 0. Koniec";
       cout << endl << ">> ";
     }
 
     void pokazListeProduktow()
     {
        widok.pokazProduktyWTabeli(&lista);
     }
 
     void dodajProdukt()
     {
     }
 
     void zarzadzaj()
     {
       const int KONIEC = 0;
       int idOpcji;
 
       do
       {
          pokazMenu();
          cin >> idOpcji;
          switch(idOpcji)
          {
             case 1 : pokazListeProduktow();
                      break;
             case 2 : dodajProdukt();
                      break;
             case 3 : ;
                      break;
          }
       }
       while(idOpcji != KONIEC);
     }
  private:
     ListaProduktow lista;
     WidokListyProduktow widok;
     ZapisOdczytListyProduktowIOStream zapisOdczyt;
};
 
int main()
{
  ManagerListyProduktow manager;
 
  manager.zarzadzaj();
 
  return EXIT_SUCCESS;
}
