#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

/** @brief A program alapjául szolgáló struktúra.
* A program láncolt listát használ. Egy ilyen rekord ebből a struktúrából épül fel.
*/

typedef struct Rekord Rekord;

struct Rekord
{
    int ev;
    int honap;
    int nap;
    int ora;
    int perc;
    char hely[26];
    char nev[26];
    char megjegyzes[51];
    int sorszam;
    Rekord *link; /**@brief a következő rekord elemre mutató pointer.*/
};

#endif // STRUKTURA_H_INCLUDED
