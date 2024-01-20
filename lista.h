#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "struktura.h"

/** @brief Listaépítő függvény.
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @warning A függvény dinamikusan foglal memóriát. A hívó feladata ezt felszabadítani.
* @returns start Visszaadja a lista fejét.
* Lefoglalja a dinamikus memóriát, majd a felhasználótól bekért adatokkal feltölti azt és végül a megfelelő helyre befűzi a listában.
* Rendezve építi fel.
* Majd meghívja a sorszamjavitas függvényt, a sorszámozás elvégzéséhez.
*/
Rekord *hozzaadas(Rekord *start);

/** @brief Listakiíró függvény.
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @returns void Nincs visszatérési értéke.
* Végigmegy a listán és kiírja a listaelemekben eltárolt adatokat a konzolra.
*/
void kiiras(Rekord *start);

/** @brief Segédfüggvény a sorszámozás elvégzéséhez.
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @returns void Nincs visszatérési értéke.
* Végigmegy a listán és minden listaelemnek ad egy sorszámot 1-től elkezdve.
* Több függvény használja segítségként. (hozzaadas, torles, fajlolvas)
*/
void sorszamjavitas(Rekord* start);

/** @brief Felszabadító függvény.
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @returns void Nincs visszatérési értéke.
* Végigmegy a listán és a dinamikusan lefoglalt memóriaterületeket felszabadítja.
*/
void felszabadit(Rekord *start);

/** @brief Listaelem törlő függvény.
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @returns start Visszaadja a láncolt lista fejét, mivel elképzelhető, hogy elem törlése esetén ez módosul.
* A felhasználó által megadott sorszámú elemet felszabadítja és összeköti az előző és a következő listaelemet.
* Majd meghívja a sorszamjavitas függvényt, hogy a sorszámozás a következő megjelenítés esetén folytonos legyen.
*/
Rekord *torles(Rekord *start);

/** @brief Függvény a listában való kereséshez
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @returns void Nincs visszatérési értéke.
* Bekér a felhasználótól egy sztringet, majd végigmegy a listán addig, amíg egy ilyen nevű rekordot nem talál és kiírja a konzolra. (Csak teljes egyezés esetén talál.)
*/
void kereses(Rekord *start);

/** @brief Függvény egy listaelem módosításához.
* @param start  Átveszi a láncolt lista első elemét(fejét).
* @returns void Nincs visszatérési értéke.
* Bekéri a felhasználótól, hogy melyik sorszámú elemet szeretné módosítani, majd ha van ilyen elem, akkor megkérdezi, hogy azon belül mit szeretne módosítani és el is végzi a módosítást.
*/
void modositas(Rekord *start);

#endif // LISTA_H_INCLUDED
