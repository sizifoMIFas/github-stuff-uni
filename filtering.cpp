#include "filtering.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "clock.h"
#include "rikiavimas.h"
using namespace std;

pair<vector<studentas>, vector<studentas>> studentsplit(const vector<studentas>& visistudentai){

    vector<studentas> nerdai;
    vector<studentas> nelaimingi;

    for (const auto& s : visistudentai){
        if (s.rezvidurkis < 5){
            nelaimingi.push_back(s);
        } else {
            nerdai.push_back(s);
        }
    }

    pair <vector<studentas>, vector<studentas>> lists = make_pair(nerdai, nelaimingi);
    return lists;

}


void gradedfiles(const vector<studentas>& nerdai, const vector<studentas>& nelaimingi, string pavadinimas){

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


void rusiavimoinfo(int rusiavimas, string paskutinisfailas, const vector<studentas>& visistudentai){

    cout << "studentai rusiuojami..." << endl;
    auto t = clockstart();
    auto [nerdai, nelaimingi] = studentsplit(visistudentai);
    cout << "studentai surusiuoti per: " << clockend(t) << " sekundes" << endl;
    cout << "failai rikiuojami..." << endl;
    auto t2 = clockstart();

    if (rusiavimas == 1){
        sort(nerdai.begin(), nerdai.end(), pagalVarda);
        sort(nelaimingi.begin(), nelaimingi.end(), pagalVarda);
    } else if (rusiavimas == 2){
        sort(nerdai.begin(), nerdai.end(), pagalPavarde);
        sort(nelaimingi.begin(), nelaimingi.end(), pagalPavarde);
    } else {
        sort(nerdai.begin(), nerdai.end(), pagalGalutini);
        sort(nelaimingi.begin(), nelaimingi.end(), pagalGalutini);
    }
    cout << "failai surikiuoti per: " << clockend(t2) << " sekundes" << endl;

    cout << "irasomi failai..." << endl;
    auto t3 = clockstart();
    gradedfiles(nerdai, nelaimingi, paskutinisfailas);
    cout << "failai irasyti per: " << clockend(t3) << " sekundes" << endl;
}