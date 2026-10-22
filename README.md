# Studentu galutiniu balu programa (v0.2)
 
C++ programa, kuri nuskaito studentu duomenis, apskaiciuoja galutinius balus, suskirsto studentus i dvi grupes ir iraso jas i atskirus failus. Taip pat matuojamas kiekvieno zingsnio greitis.
 
## Ka daro programa
 
- **Galutinis balas** = 0.4 * namu darbu vidurkis (arba mediana) + 0.6 * egzaminas.
- **Failu generavimas:** sugeneruoja 5 atsitiktiniu studentu saraso failus (1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 irasu). Eilutes formatas: `vardasN pavardeN nd1 nd2 nd3 nd4 nd5 egzaminas`.
- **Skirstymas i dvi grupes** pagal galutini bala (naudojamas vidurkio variantas):
  - galutinis balas < 5.0 -> `nelaimingi_<failo pavadinimas>`
  - galutinis balas >= 5.0 -> `nerdai_<failo pavadinimas>`
- **Rusiavimas:** pries irasant i failus naudotojas pasirenka, pagal ka surusiuoti: varda, pavarde ar galutini bala.
- **Greicio analize:** matuojamas failu generavimas, nuskaitymas, skirstymas i grupes ir irasymas i du naujus failus.
## Meniu
 
1. vardo, pavardes ivedimas (rankinis arba atsitiktiniai pazymiai)
2. rezultatai (isvedimas, galimybe suskirstyti i dvi grupes ir irasyti i failus)
3. skaitymas is failo
4. failu generavimas
5. isvalyti sarasa
6. automatinis testas (kartoja nuskaityma, skirstyma ir irasyma ir isveda vidurkius)
7. isejimas is programos
## Kaip sucompile'int ir paleisti
 
```zsh
g++ -std=c++17 -O2 main.cpp clock.cpp skaiciavimai.cpp rikiavimas.cpp menu.cpp grades.cpp generators.cpp reading.cpp filtering.cpp testas.cpp -o main && ./main
```
 
## Projekto struktura
 
| Failas | Paskirtis |
|---|---|
| `main.cpp` | meniu ir pagrindinis ciklas |
| `studentas.h` | `studentas` struktura |
| `skaiciavimai.h/.cpp` | galutinio balo, vidurkio ir medianos skaiciavimas |
| `rikiavimas.h/.cpp` | studentu palyginimo funkcijos (pagal varda, pavarde, galutini bala) |
| `menu.h/.cpp` | isvedimas ir meniu pasirinkimai |
| `grades.h/.cpp` | pazymiu ivedimas ir atsitiktiniai pazymiai |
| `generators.h/.cpp` | testiniu failu generavimas |
| `reading.h/.cpp` | duomenu nuskaitymas is failo |
| `filtering.h/.cpp` | skirstymas i grupes ir irasymas i failus |
| `clock.h/.cpp` | laiko matavimas |
| `testas.h/.cpp` | automatinis greicio testas |
 
## Testavimo sistema
 
- Kompiuteris: MacBook Pro (M4 Max)
- Kompiliatorius: g++, `-std=c++17 -O2`
- Konteineris: `std::vector`
- Failai sugeneruoti vieną kartą ir naudoti visuose testuose.
- Kiekvienas laikas yra **5 paleidimu vidurkis** (sekundemis).
- Rusiavimo zingsnis i lentele neiskaiciuotas.
## Rezultatai
 
| irasu | nuskaitymas | skirstymas | irasymas | viso |
|---|---|---|---|---|
| 1000 | 0.0009 | 0.0001 | 0.0007 | 0.0017 |
| 10000 | 0.0067 | 0.0005 | 0.0038 | 0.0110 |
| 100000 | 0.0543 | 0.0039 | 0.0278 | 0.0860 |
| 1000000 | 0.5465 | 0.0447 | 0.2683 | 0.8594 |
| 10000000 | 5.6205 | 0.4774 | 2.7081 | 8.8059 |
 
 # v0.3: std::vector ir std::list palyginimas

## Testavimo sistema
- CPU: Apple M4 Max
- RAM: 36 GB
- Diskas: SSD
- Kompiliatorius: g++ -std=c++17 -O2
- Metodika: kiekvienam failo dydžiui atlikti 3 testai, pateikiamas jų vidurkis. Abiem konteineriams naudoti tie patys failai.
- Rūšiavimas: pagal galutinį balą (3 pasirinkimas), abiem konteineriams vienodai.
- Vidurkiai apskaičiuoti naudojant nedidelį shell skriptą, kuris kelis kartus paleido programą.

## Rezultatai (sekundėmis, 3 testų vidurkis)

| Studentų sk. | Konteineris | Skaitymas | Skirstymas | Rūšiavimas | Rašymas |
|---|---|---|---|---|---|
| 1k | list | 0.0008 | 0.0000 | 0.0000 | 0.0000 |
| 1k | vector | 0.0011 | 0.0000 | 0.0000 | 0.0000 |
| 10k | list | 0.0058 | 0.0000 | 0.0000 | 0.0000 |
| 10k | vector | 0.0062 | 0.0000 | 0.0000 | 0.0000 |
| 100k | list | 0.0536 | 0.0100 | 0.0100 | 0.0300 |
| 100k | vector | 0.0556 | 0.0067 | 0.0000 | 0.0300 |
| 1m | list | 0.5484 | 0.0733 | 0.2000 | 0.2933 |
| 1m | vector | 0.5623 | 0.0600 | 0.0333 | 0.2433 |
| 10m | list | 5.5459 | 0.7633 | 5.0467 | 3.0133 |
| 10m | vector | 5.6550 | 0.6133 | 0.3633 | 2.4267 |

## Išvados
- Didžiausias skirtumas matomas rūšiuojant. Su 10m įrašų list užtrunka apie 5 s, o vector apie 0.36 s (maždaug 14 kartų greičiau). Vector elementai atmintyje guli vienas šalia kito, todėl procesorius juos skaito greitai. List elementai išsimėtę po atmintį, todėl kiekvienas žingsnis yra lėtas šuolis į kitą vietą.
- Skaitymo laikai abiem konteineriams panašūs, nes juos riboja disko greitis ir teksto apdorojimas.
- Skirstymas į dvi grupes ir rašymas į failus su vector yra šiek tiek greitesni.
- 1k ir 10k dydžių laikai per maži, kad juos būtų galima tiksliai išmatuoti naudojant šį laikmatį.
- Atminties adresai: list elementų adresai nesikeičia, kol elementas saugomas. Vector, kai pritrūksta vietos, perkelia visus elementus į naują atminties bloką, todėl ankstesnių elementų adresai gali pasikeisti.