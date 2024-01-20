# ﻿**Használat**

Az alkalmazást egyszerűen lehet kezelni. Grafikus megjelenítés nélküli konzolos felületen az indítást követően azonnal megjelenő menü segítségével. Ezek után választania kell a felsorolt lehetőségek közül. A menüelemek sorszámmal rendelkeznek, így ezek közül a sorszámok közül egyet beírva elérheti a kívánt funkciót. A következő formátumban:
<strong><code>*<szám> (1-6 között)*</code></strong>

## **1. Megjelenítés**
Ezt a menüpontot választva az eddig hozzáadott rekordok kiíródnak a konzolra.

## **2. Hozzáadás**
Ezt a menüpontot választva egy új rekordot van lehetőség létrehozni. Figyelni kell a formátumra, minden elem után szóközt kell tenni (sztringekben nem lehet szóköz):
<strong><code>*<ÉÉÉÉ HH NN ÓÓ PP HELY ELNEVEZÉS MEGJEGYZÉS>*</code></strong>

## **3. Törlés**
A felhasználónak a megjelenő rekordok listájából a megfelelő sorszám beírásával ki kell választania a törlendő elemet. A sorszám beírásának a következő formátumban kell történnie:
<strong><code>*<szám>*</code></strong>

## **4. Módosítás**
A felhasználónak a megjelenő rekordok listájából ki kell választania, hogy melyik sorszámú rekordot szeretné módosítani.
<strong><code>*<szám>*</code></strong>

Majd ezek után ki kell választania, hogy azon a rekordon belül mit szeretne módosítani
<strong><code>*<betű> (d: dátum, i: idő, h: hely, e: elnevezés, m: megjegyzés)*</code></strong>

Ezek után az előbb kiválasztott rekordban a módosítandó terület módosítására van lehetőség a megfelelő formátumban.

## **5. Keresés**
A felhasználónak meg kell adnia egy sztringet, ami alapján a program megkeresi az adott elnevezéssel rendelkező határidőnaplóbejegyzést és kiírja a konzolra.
<strong><code>*<"sztring">*</code></strong>

## **6. Kilépés**
Ezt a menüpontot választva a program kilép, azonban előtte elmenti a futás közben megadott rekordokat az adatbázisba.
