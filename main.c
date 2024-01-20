#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#include "lista.h"
#include "struktura.h"
#include "menu.h"
#include "fajlkezeles.h"

int main()
{
    Rekord *start=NULL;             //a lista fejének deklarálása, kezdetben nem mutat sehova
    start=fajlolvas(start);
    while(1)
    {

        int valasztas = menu();

        switch (valasztas)
        {
        case 1:
            system("cls");
            kiiras(start);
            break;

        case 2:
            system("cls");
            start=hozzaadas(start);
            break;

        case 3:
            system("cls");
            start=torles(start);
            break;

        case 4:
            system("cls");
            modositas(start);
            break;

        case 5:
            system("cls");
            kereses(start);
            break;

        case 6:
            fajlbair(start);
            felszabadit(start);
            exit(0);
            break;

        default:
            system("cls");
            printf("A kovetkezo szamok az elfogadottak: <1-6>\n\n"); //hibakezelés, amennyiben rossz az input, ez fut le
        }
    }
    return 0;
}
