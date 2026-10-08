#include "menu.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void printHeader(){

    cout << fixed << setprecision(2);
    cout << left
    << setw(20) << "Pavarde"
    << setw(20) << "vardas"
    << setw(20) << "Galutinis (vid)"
    << setw(20) << "Galutinis (med)" << endl;

}

void results(studentas s){

    cout << left
    << setw(20) << s.pavarde
    << setw(20) << s.vardas
    << setw(20) << s.rezvidurkis
    << setw(20) << s.rezmedian << endl;

}

string filechoice(){

    string file;

    while (file.empty()){

        int pasirinkimas;
        int filechoice;

        cout << "" << endl;
        cout << "is kokiu failu nori skaityti?" << endl;
        cout << "1. pries tai pateiktu (kursiokai.txt ir pan)" << endl;
        cout << "2. ka tik sugeneruotu failu (iki 10,000,000 studentu)" << endl;
        cout << "(spausk 0 kad sugrizti)" << endl;
        cout << "pasirinkimas" << endl;
        cin >> pasirinkimas;

        if (pasirinkimas == 0){
            return {};
        }

        else if (pasirinkimas == 1){
            
            cout << "" << endl;
            cout << "duoti failai" << endl;
            cout << "1. kursiokai.txt" << endl;
            cout << "2. 10k studentu" << endl;
            cout << "3. 100k studentu" << endl;
            cout << "4. 1m studentu" << endl;
            cout << "pasirinkimas" << endl;
            cin >> filechoice;

            if (filechoice == 1){
                file = "kursiokai.txt";
            } else if (filechoice == 2){
                file = "studentai10000.txt";
            } else if (filechoice == 3){
                file = "studentai100000.txt";
            } else if (filechoice == 4){
                file = "studentai1000000.txt";
            } else {
                cout << "error, bandyk vel" << endl;
            }
        }

        else if (pasirinkimas == 2){

            cout << "" << endl;
            cout << "sugeneruoti failai" << endl;
            cout << "1. 1k studentu" << endl;
            cout << "2. 10k studentu" << endl;
            cout << "3. 100k studentu" << endl;
            cout << "4. 1m studentu" << endl;
            cout << "5. 10m studentu" << endl;
            cout << "pasirinkimas" << endl;
            cin >> filechoice;

            if (filechoice == 1){
                file = "studentai_generated1000.txt";
            } else if (filechoice == 2){
                file = "studentai_generated10000.txt";
            } else if (filechoice == 3){
                file = "studentai_generated100000.txt";
            } else if (filechoice == 4){
                file = "studentai_generated1000000.txt";
            } else if (filechoice == 5){
                file = "studentai_generated10000000.txt";
            } else {
                cout << "error, bandyk vel" << endl;
            }
        }

        else if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 0){
            cout << "error, bandyk vel" << endl;
        }
    }

    return file;

}

int rusiavimomenu(){

    int pasirinkimas = 0;

    while (pasirinkimas < 1 || pasirinkimas > 3){

        cout << "" << endl;
        cout << "kaip surusiuoti failus?" << endl;
        cout << "1. pagal varda" << endl;
        cout << "2. pagal pavarde" << endl;
        cout << "3. pagal galutini bala" << endl;
        cout << "pasirinkimas:" << endl;

        if (!(cin >> pasirinkimas)){
            cin.clear();
            cin.ignore(10000, '\n');
            pasirinkimas = 0;
        }

        if (pasirinkimas < 1 || pasirinkimas > 3){
            cout << "error, bandyk vel" << endl;
        }
    }

    return pasirinkimas;

}