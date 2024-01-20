#ifndef FAJLKEZELES_H_INCLUDED
#define FAJLKEZELES_H_INCLUDED

/** @brief F�jlba�r� f�ggv�ny.
* @param start  A l�ncolt lista els� elem�t veszi �t(fej�t).
* @returns void Nincs visszat�r�si �rt�ke.
* V�gigmegy a list�n �s a rekordokat soronk�nt ki�rja egy fileba(adatbazis.txt).
*/
void fajlbair(Rekord *start);

/** @brief F�jlb�l olvas� f�ggv�ny.
* @param start  A l�ncolt lista els� elem�t veszi �t(fej�t).
* @warning A f�ggv�ny dinamikusan foglal mem�ri�t, amennyiben a file nem �res. A h�v� feladata ezt felszabad�tani.
* @returns start Visszat�r�si �rt�ke a lista feje.
* V�gigmegy a fileon(adatbazis.txt) �s a be�rkez� rekordokb�l, amik soronk�nt vannak t�rolva, fel�p�t egy list�t.
* Majd megh�vja a sorszamjavitas f�ggv�nyt a sorsz�moz�s kijav�t�s�hoz.
*/
Rekord *fajlolvas(Rekord *start);

#endif // FAJLKEZELES_H_INCLUDED
