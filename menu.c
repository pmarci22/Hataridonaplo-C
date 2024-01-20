#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

int menu()
{

    int valasztas;

    printf("Hataridonaplo\n");
    printf("Kerem valasszon az alabbi lehetosegek kozul:\n");
    printf("1. Megjelenites\n");
    printf("2. Hozzaadas\n");
    printf("3. Torles\n");
    printf("4. Modositas\n");
    printf("5. Kereses\n");
    printf("6. Mentes es kilepes\n\n");

    scanf("%d", &valasztas);

    return valasztas; //visszaadja a számot amit a felhasználó választ
}
