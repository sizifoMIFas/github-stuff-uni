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
 