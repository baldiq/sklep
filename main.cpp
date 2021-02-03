#include <iostream>
#include <cstdlib>
#include "listaproduktow.h"
#include "produkty.h"
#include "zapisodczytlistyplikow.h"
#include "managerlistyproduktow.h"


using namespace std;


int main()
{
    ManagerListyProduktow manager;

    manager.zarzadzaj();

    return 0;
}
