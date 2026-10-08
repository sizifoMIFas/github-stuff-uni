#include "reading.h"
#include <fstream>
#include <iostream>
#include "skaiciavimai.h"
#include "studentas.h"
#include <sstream>

using namespace std;

vector<studentas> fileread(string file){

    ifstream failas(file);
    vector<studentas> sarasas;
    string eilute;

    if (!failas.is_open()){
        cout << "nepavyko atidaryti failo. galbut uzmirsai sugeneruot failus." << endl;
        return sarasas;
    }

    while (getline(failas, eilute)){

        if (eilute.empty()) continue;

        stringstream ss(eilute);
        studentas s;
        ss >> s.pavarde >> s.vardas;

        vector<int> visiSkaiciai;
        int skaicius;
        while (ss >> skaicius) {
            visiSkaiciai.push_back(skaicius);
        }

        if (visiSkaiciai.empty()) continue;

        s.egzrezultatas = visiSkaiciai.back();
        visiSkaiciai.pop_back();
        s.ndpazymiai = visiSkaiciai;
        s.rezvidurkis = vidurkiscalc(s.ndpazymiai, s.egzrezultatas);
        s.rezmedian = mediancalc(s.ndpazymiai, s.egzrezultatas);
        sarasas.push_back(s);
        
    }

    failas.close();
    return sarasas;

}