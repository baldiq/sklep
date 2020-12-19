
ManagerListyProduktow::ManagerListyProduktow()
{
    cout << "Zarzadzam lista produktow" << endl;
    ZapisOdczytListyPlikow zapisOdczyt;
    zapisOdczyt.odczytaj()
}

ManagerListyProduktow::~ManagerListyProduktow()
{
    cout << "Nacisnij enter by zakonczyc...";
    cin.ignore();
    cin.get();
}

void ManagerListyProduktow::pokazMenu()
{
    cout << "Dostepne opcje\n\t1. Pokaz produkty\n\t2. Dodaj produkt\n\t";
    cout << "\n\t 0. Koniec";
    cout << endl << " >> ";
}

int ManagerListyProduktow::dodajProdukt()
{
    // dodawanie produktu
}

void ManagerListyProduktow::zarzadzaj()
{
    const int KONIEC = 0;
    int idOpcji;

    do
    {
        pokazMenu();
        cin >> idOpcji;

        switch(idOpcji)
        {
            case 1: pokazMenu();
                break;
            case 2: dodajProdukt();
                break;
            case 3: ;
                break;
        }
    }
    while (idOpcji != KONIEC);
}

