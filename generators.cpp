#include "generators.h"
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void filegenerator(){

    int kiekis = 1000;

    while (kiekis < 10000001){

    string pavadinimas = "studentai_generated" + to_string(kiekis) + ".txt";
    ofstream file(pavadinimas);

    for (int i = 1; i <= kiekis; i++){ // zmoniu numeravimas
        file << "vardas" << i << " pavarde" << i;
    for (int j = 0; j < 5; j++){ // nd, po 5
        file << " " << (rand() % 10 + 1);
    }

    file << " " << (rand() % 10 + 1) << "\n"; // egzas
    }

    kiekis *= 10;
    }   

}