#include "filtering.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "clock.h"
#include "rikiavimas.h"
using namespace std;

pair<konteineris, konteineris> studentsplit(const konteineris& visistudentai){

    konteineris nerdai;
    konteineris nelaimingi;

    for (const auto& s : visistudentai){
        if (s.rezvidurkis < 5){
            nelaimingi.push_back(s);
        } else {
            nerdai.push_back(s);
        }
    }

    return make_pair(nerdai, nelaimingi);

}


konteineris studentsplit2(konteineris& visistudentai){

    konteineris nelaimingi;

    auto it = visistudentai.begin();
    while (it != visistudentai.end()){
        if (it->rezvidurkis < 5){
            nelaimingi.push_back(*it);
            it = visistudentai.erase(it);
        } else {
            ++it;
        }
    }

    return nelaimingi;
}


konteineris studentsplit3(konteineris& visistudentai){

    auto riba = std::stable_partition(visistudentai.begin(), visistudentai.end(),
        [](const studentas& s){ return s.rezvidurkis >= 5; });

    konteineris nelaimingi(riba, visistudentai.end());

    visistudentai.erase(riba, visistudentai.end());

    return nelaimingi;
}


void gradedfiles(konteineris& nerdai, konteineris& nelaimingi, string pavadinimas){

    string nerdfile = "nerdai_" + pavadinimas;
    ofstream failas1(nerdfile);

    for (const auto& s : nerdai){
        failas1 << s.vardas << " " << s.pavarde << " " << s.rezvidurkis << " " << s.rezmedian << "\n";
    }

    string nelaimingifile = "nelaimingi_" + pavadinimas;
    ofstream failas2(nelaimingifile);

    for (const auto& s : nelaimingi){
        failas2 << s.vardas << " " << s.pavarde << " " << s.rezvidurkis << " " << s.rezmedian << "\n";
    }

}


void rusiavimoinfo(int rusiavimas, string paskutinisfailas, konteineris& visistudentai, int strategija){

    konteineris nerdai, nelaimingi;

    cout << "studentai rusiuojami..." << endl;
    auto t = clockstart();

    if (strategija == 1){
        tie(nerdai, nelaimingi) = studentsplit(visistudentai);
    } else if (strategija == 2){
        nelaimingi = studentsplit2(visistudentai);
        nerdai.swap(visistudentai);
    } else {
        nelaimingi = studentsplit3(visistudentai);
        nerdai.swap(visistudentai);
    }

    cout << "studentai surusiuoti per: " << clockend(t) << " sekundes" << endl;
    cout << "studentu atmintyje: " << visistudentai.size() + nerdai.size() + nelaimingi.size() << endl;

    auto t2 = clockstart();

    if (rusiavimas == 1){

        rikiuoti(nerdai, pagalVarda);
        rikiuoti(nelaimingi, pagalVarda);

    } else if (rusiavimas == 2){

        rikiuoti(nerdai, pagalPavarde);
        rikiuoti(nelaimingi, pagalPavarde);

    } else {

        rikiuoti(nerdai, pagalGalutini);
        rikiuoti(nelaimingi, pagalGalutini);

    }

    cout << "failai surikiuoti per: " << clockend(t2) << " sekundes" << endl;
    cout << "irasomi failai..." << endl;

    auto t3 = clockstart();
    gradedfiles(nerdai, nelaimingi, paskutinisfailas);
    cout << "failai irasyti per: " << clockend(t3) << " sekundes" << endl;
}