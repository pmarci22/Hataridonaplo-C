#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struktura.h"
#include "lista.h"
#include "debugmalloc.h"

Rekord *hozzaadas(Rekord *start)
{
    Rekord *temp;
    Rekord *rekord;
    Rekord *temp2;

    temp = start;
    temp2 = NULL;

    rekord = (Rekord *)calloc(1,sizeof(Rekord));        //dinamikus foglalás, késõbb fel kell szabadítani
    if (rekord == NULL)
    {
        printf("Nem sikerult a foglalas.");
        return start;
    }
    printf("Irja be az adatokat:<ev(EEEE) honap(HH) nap(NN) ora(OO) perc(PP) hely nev megjegyzes(sztringek space nelkul)>\n");
    scanf("%d %d %d %d %d %s %s %s",&rekord->ev, &rekord->honap, &rekord->nap, &rekord->ora, &rekord->perc, rekord->hely, rekord->nev, rekord->megjegyzes);

    while (temp != NULL && (temp->ev < rekord->ev || temp->honap < rekord->honap || temp->nap < rekord->nap || temp->ora < rekord->ora || temp->perc < rekord->perc))
    {
        temp2 = temp;
        temp = temp->link;
    }

    if (temp2 == NULL)
    {
        rekord->link = start;
        start = rekord;
    }
    else
    {
        temp2->link = rekord;
        rekord->link = temp;
    }

    sorszamjavitas(start); //javítja a sorszámokat
    return start;
}

void sorszamjavitas(Rekord *start)             //Új rekord hozzáadása esetén végigmegy a listán és a sorszámozást elvégzi
{
    Rekord *temp;
    int i = 1;
    temp=start;
    while (temp!=NULL)
    {
        temp->sorszam=i;
        i++;
        temp=temp->link;
    }
}

void kiiras(Rekord *start)
{
    Rekord *temp;
    temp=start;

    if (start == NULL)                  //vizsgáljuk, hogy van-e rekord
    {
        printf("Nincsenek rekordok\n");
    }
    while(temp!=NULL)
    {
        printf("%d:  %d.%02d.%02d. %02d:%02d |HELY: %s | |NEV: %s | |MEGJEGYZES: %s |\n",temp->sorszam, temp->ev, temp->honap, temp->nap, temp->ora, temp->perc, temp->hely, temp->nev, temp->megjegyzes);
        temp=temp->link;
    }
}

void felszabadit(Rekord *start)
{
    Rekord *temp;
    temp=start;
    while(temp != NULL)                     //bejárja a listát
    {
        Rekord *next = temp->link;
        free(temp);                         //felszabadít
        temp=next;
    }
}

Rekord *torles(Rekord *start)
{

    Rekord *temp=NULL;
    Rekord *temp2=start;

    int torlendo;
    printf("Melyik sorszamu elemet szeretned torolni?\n");
    scanf("%d",&torlendo);

    while(temp2 != NULL && temp2->sorszam != torlendo) //bejárja a listát, amig nem találja meg a törlendőt
    {
        temp = temp2;
        temp2 = temp2->link;
    }
    if(temp2==NULL)
    {

    }
    else if (temp == NULL)
    {
        Rekord *ujstart=temp2->link;
        free(temp2);
        start=ujstart;
    }
    else
    {
        temp->link = temp2->link;
        free(temp2);
    }
    sorszamjavitas(start); //javítja a sorszámokat
    return start;
}

void kereses(Rekord *start)
{
    Rekord *temp=start;
    char keresett[25];
    int talalat = 0;
    printf("Melyik nevu rekordot keresed?\n");
    scanf("%s", keresett);

    while (temp != NULL)
    {
        if (strcmp(keresett,temp->nev)==0)
        {
            printf("%d:  %d.%02d.%02d. %02d:%02d |HELY: %s | |NEV: %s | |MEGJEGYZES: %s |\n",temp->sorszam, temp->ev, temp->honap, temp->nap, temp->ora, temp->perc, temp->hely, temp->nev, temp->megjegyzes);
            talalat = 1;
        }
        temp = temp->link;
    }
    if(talalat==0)
    {
        printf("Nincs ilyen nevu rekord a listaban.\n");
    }

}

void modositas(Rekord *start)
{

    Rekord *temp=start;
    int siker = 0;
    char mit;

    int modositando;
    printf("Melyik sorszamu elemet szeretned modositani?\n");
    scanf("%d", &modositando);

    while(temp != NULL && temp->sorszam != modositando)
    {
        temp = temp->link;
    }

    if(temp==NULL)
    {
        printf("Nincs ilyen sorszamu elem.\n");
        return;
    }

    printf("A %d. sorszamu listaelemen mit szeretnel modositani?(d: datum, i: ido, h: hely, e: elnevezes, m: megjegyzes)\n", modositando);

    while(siker!=1)
    {
        scanf("%c", &mit);

        switch (mit)
        {
        case 'd':
            printf("Adja meg az uj datumot: EEEE HH NN\n");
            scanf("%d %d %d",&temp->ev, &temp->honap, &temp->nap);
            siker = 1;
            break;

        case 'i':
            printf("Adja meg az uj idot: OO PP\n");
            scanf("%d %d",&temp->ora, &temp->perc);
            siker = 1;
            break;

        case 'h':
            printf("Adja meg az uj helyet: (sztring max 25 karakter)");
            scanf("%s",temp->hely);
            siker = 1;
            break;

        case 'e':
            printf("Adja meg az uj nevet: (sztring max 25 karakter)\n");
            scanf("%s",temp->nev);
            siker = 1;
            break;

        case 'm':
            printf("Adja meg az uj megjegyzest: (sztring max 50 karakter)\n");
            scanf("%s",temp->megjegyzes);
            siker = 1;
            break;
        default:
            printf("Nem megfelelo karakter.");
            break;

        }
    }

}
