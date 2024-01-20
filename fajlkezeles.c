#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#include "struktura.h"
#include "lista.h"

void fajlbair(Rekord *start)
{
    FILE *fp;
    Rekord *temp = start;

    fp = fopen("adatbazis.txt", "w");

    if (fp == NULL)
    {
        perror("fajl megnyitasa sikertelen.\n");
        return;
    }

    while(temp !=NULL)
    {
        fprintf(fp,"%d %d %d %d %d %s %s %s\n",temp->ev,temp->honap,temp->nap,temp->ora,temp->perc,temp->hely,temp->nev,temp->megjegyzes);
        temp=temp->link;
    }
    fclose(fp);
}

Rekord *fajlolvas(Rekord *start)
{
    FILE *fp;

    fp = fopen("adatbazis.txt", "r");

    if (fp == NULL)
    {
        perror("fajl megnyitasa sikertelen.\n");
        return start;
    }

    Rekord *temp;
    Rekord *rekord;
    Rekord *temp2;

    char sor[300];

    while(fgets(sor, 300, fp)!=NULL)
    {

        if (start==NULL)               //megvizsgáljuk, hogy már van-e rekord
        {
            rekord = (Rekord *)calloc(1,sizeof(Rekord));        //dinamikus foglalás, késõbb fel kell szabadítani
            if (rekord == NULL)
            {
                printf("Nem sikerult a foglalas.");
                return start;
            }
            start = rekord;
            sscanf(sor,"%d %d %d %d %d %s %s %s",&rekord->ev, &rekord->honap, &rekord->nap, &rekord->ora, &rekord->perc, rekord->hely, rekord->nev, rekord->megjegyzes);
            rekord->sorszam = 1;
            start->link=NULL;

        }
        else
        {
            temp = (Rekord *)calloc(1,sizeof(Rekord));          //dinamikus foglalás, késõbb fel kell szabadítani
            if (temp == NULL)
            {
                printf("Nem sikerult a foglalas.");
                return start;
            }
            sscanf(sor,"%d %d %d %d %d %s %s %s",&temp->ev, &temp->honap, &temp->nap, &temp->ora, &temp->perc, temp->hely, temp->nev, temp->megjegyzes);
            temp->link=NULL;
            temp2=start;
            while(temp2->link != NULL)
            {
                temp2 = temp2->link;
            }
            temp2->link = temp;
        }

    }
    sorszamjavitas(start);
    fclose(fp);

    return start;

}

