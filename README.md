# Studentu galutiniu balu programa (v1.0)

C++ programa, kuri nuskaito studentu duomenis, apskaiciuoja galutinius balus, suskirsto studentus i dvi grupes ("nelaimingi" ir "nerdai") ir iraso jas i failus. Versijoje v1.0 palyginamos trys skirstymo strategijos su dviem konteineriais (`std::vector` ir `std::list`).

## Releasai

| Releasas | Kas nauja |
|---|---|
| v.pradinė | struct + vector programa, vidurkis/mediana, atsitiktiniai pazymiai, meniu |
| v0.1 | duomenu nuskaitymas is failo, rusiavimas, isvesties lygiavimas |
| v0.2 | failu generavimas, skirstymas i dvi grupes, greicio matavimas |
| v0.3 | `vector` ir `list` palyginimas, atminties adreso isvedimas |
| v1.0 | trys skirstymo strategijos abiem konteineriams, `Makefile`, automatinis testas, rezultatu analize |

## Diegimas ir paleidimas

Reikia `g++` (C++17) ir `make`.

```zsh
git clone https://github.com/sizifoMIFas/github-stuff-uni.git
cd github-stuff-uni
git checkout v1.0
make
```

`make` sukompiliuoja dvi programos versijas:

```zsh
./main_list      # konteineris: std::list
./main_vector    # konteineris: std::vector
```

Meniu: 1 ivedimas, 2 rezultatai (cia pasirenkama rusiavimas ir skirstymo strategija 1-3), 3 skaitymas is failo, 4 failu generavimas, 5 isvalyti sarasa, 6 isejimas.

Rezultatai (option 2) rasomi i `rezultatai.txt`, o suskirstyti studentai i `nerdai_*` ir `nelaimingi_*` failus. `make clean` ismeta sukompiliuotas programas ir sugeneruotus failus.

## Skirstymo strategijos

Studentas yra "nelaimingas", jei galutinis balas (vidurkis) < 5, kitaip - "nerdai".

1. **Strategija 1** (`studentsplit`): sukuriami du nauji konteineriai ir kiekvienas studentas nukopijuojamas i viena is ju. Pradinis konteineris nekeiciamas, todel kiekvienas studentas atmintyje yra du kartus.
2. **Strategija 2** (`studentsplit2`): sukuriamas vienas naujas konteineris "nelaimingi", o nelaimingi studentai po vieno istrinami is pradinio. Pradiniame lieka tik nerdai.
3. **Strategija 3** (`studentsplit3`): strategijos 2 idejos optimizacija su `std::stable_partition`. Vienu praejimu visi nerdai perkeliami i konteinerio prieki, nelaimingieji nukopijuojami i nauja konteineri ir istrinami vienu `erase` kvietimu. Nereikia trinti po vieno.

## Testavimas

- Kompiuteris: MacBook (Apple M4 Max, 36 GB RAM), macOS 27.2
- Kompiliatorius: `g++ -std=c++17 -O2`
- Failai: `studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt` (visuose testuose tie patys)
- Kiekvienas laikas yra **5 paleidimu vidurkis** (sekundemis), gautas skriptu `benchmark.zsh`
- Visi neapdoroti rezultatai yra faile `benchmark_laikai.txt`.
- Strategijoms 2 ir 3 pries matuojant sukuriama pradinio konteinerio kopija, kuri i laika neiskaiciuota.
- Visu strategiju ir abieju konteineriu sukurti failai yra identiski (patikrinta kontroline suma), todel laikai palyginami.

## Rezultatai: skirstymas i dvi grupes (s)

| Studentu | list, strat. 1 | list, strat. 2 | list, strat. 3 | vector, strat. 1 | vector, strat. 2 | vector, strat. 3 |
|---|---|---|---|---|---|---|
| 10 000 | 0.00072 | 0.00019 | 0.00029 | 0.00053 | 0.05186 | **0.00018** |
| 100 000 | 0.00698 | 0.00191 | 0.00269 | 0.00505 | 5.11612 | **0.00178** |
| 1 000 000 | 0.07073 | **0.01893** | 0.02614 | 0.05120 | 535.4 (vienas paleidimas) | **0.01827** |

Kitu zingsniu laikai su 1 000 000 studentu (s):

| Zingsnis | list | vector |
|---|---|---|
| nuskaitymas | 0.93 | 0.94 |
| rikiavimas | 0.057 | 0.011 |
| irasymas i failus | 0.27 | 0.27 |

## Isvados

- **`vector` + strategija 2 netinka dideliems duomenims.** Kiekvienas `erase` priverstina visus uz istrinto studento esancius elementus pasislinkti, todel laikas auga kvadratiskai: 10 kartu daugiau studentu reiske apie 100 kartu daugiau laiko. Su 1 000 000 studentu uztruko apie 9 minutes (matuota viena karta).
- **`vector` + strategija 3 yra greiciausia** ir apie 2.8 karto greitesne uz strategija 1, nes `stable_partition` perrikiuoja vienu praejimu, o `erase` istrina uodega vienu kvietimu, nieko neperstumdamas.
- **`list` atveju laimi strategija 2**, nes trynimas is saraso tik pakeicia rodykles tarp kaimynu. Strategija 1 lieka letciausia (apie 3.7 karto letesne uz strategija 2 su 1 000 000 studentu). Strategija 3 `list` atveju yra arti strategijos 2, bet jos nenugali.
- **Skirstymas nera pagrindine kliutis**: su 1 000 000 studentu nuskaitymas uztrunka apie 0.93 s, o skirstymas 0.02-0.07 s (isskyrus `vector` + strategija 2).
- **Rikiavimas** su `vector` yra apie 5 kartus greitesnis nei su `list` (`list` elementai atmintyje isbarstyti, `vector` - is eiles).