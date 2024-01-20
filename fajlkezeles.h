#ifndef FAJLKEZELES_H_INCLUDED
#define FAJLKEZELES_H_INCLUDED

/** @brief Fájlbaíró függvény.
* @param start  A láncolt lista elsõ elemét veszi át(fejét).
* @returns void Nincs visszatérési értéke.
* Végigmegy a listán és a rekordokat soronként kiírja egy fileba(adatbazis.txt).
*/
void fajlbair(Rekord *start);

/** @brief Fájlból olvasó függvény.
* @param start  A láncolt lista elsõ elemét veszi át(fejét).
* @warning A függvény dinamikusan foglal memóriát, amennyiben a file nem üres. A hívó feladata ezt felszabadítani.
* @returns start Visszatérési értéke a lista feje.
* Végigmegy a fileon(adatbazis.txt) és a beérkezõ rekordokból, amik soronként vannak tárolva, felépít egy listát.
* Majd meghívja a sorszamjavitas függvényt a sorszámozás kijavításához.
*/
Rekord *fajlolvas(Rekord *start);

#endif // FAJLKEZELES_H_INCLUDED
