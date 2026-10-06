#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
using namespace std;


struct studentas{

    string vardas;
    string pavarde;
    vector<int> ndpazymiai;
    int egzrezultatas;
    double rezvidurkis;
    double rezmedian;

};


void filegenerator(){
    int kiekis = 1000;
    while ( kiekis < 10000001){
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


//    srand(time(0));
//    generuotiFaila(1000, "studentai1000.txt");
//    cout << "done" << endl;


double galutinis(double vidurkis_or_median, double egzas){

    double galutinisvid = ((double)vidurkis_or_median * 0.4) + (egzas * 0.6);
    return galutinisvid;

}


double vidurkiscalc(vector<int> ndvektorius, int examgrade){

    int suma = accumulate(ndvektorius.begin(), ndvektorius.end(), 0);
    double vidurkis = (double)suma / ndvektorius.size();
    double galutinisvid = galutinis(vidurkis, examgrade);
    
    return galutinisvid;

}


double mediancalc(vector<int> ndvektorius, int examgrade){

    double median;

    sort(ndvektorius.begin(), ndvektorius.end());
        
        if (ndvektorius.size() % 2 == true){
            median = ndvektorius[ndvektorius.size() / 2];
        } else { 
            int upper = (ndvektorius.size() / 2);
            int lower = ((ndvektorius.size() / 2) - 1);
            median = ((ndvektorius[upper] + ndvektorius[lower]) / 2.0);
        } 

    double galutinismed = galutinis(median, examgrade);
    return galutinismed;

}


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


vector<int> randomgrades(){

    random_device rd;
    vector<int> ndpazymiai;

    for (int i = 0; i < 5; ++i) {
        ndpazymiai.push_back(1 + (rd() % 10));
    }

    return ndpazymiai;

}


vector<int> ndloop(){
    
    vector<int> ndpazymiai = {};

    cout << "kokie namu darbu rezultatai?" << endl;
    cout << "(paspausk enter kai baigei ivedinet pazymius)" << endl;

    while (true) {
        string line;
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        int ndrezultatas = stoi(line); 
        ndpazymiai.push_back(ndrezultatas);
        } return ndpazymiai; 

}


bool lyginti(studentas a, studentas b) {
    if (a.pavarde != b.pavarde) {
        return a.pavarde < b.pavarde;
    }
    return a.vardas < b.vardas;
}


vector<studentas> fileread(){

    int filechoice;
    
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

        else {
            cout << "error, bandyk vel" << endl;
        }

    }
    
    ifstream failas(file);
    vector<studentas> sarasas;

    if (!failas.is_open()){
        cout << "nepavyko atidaryti failo" << endl;
        return sarasas;
    }

    string eilute;

    while (getline(failas, eilute)) {
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


int main(){

    filegenerator();

    vector<studentas> visistudentai;
    string vardas;
    string pavarde;
    string aware;
    random_device rd;
    int egzrezultatas;
    int pasirinkimas = 0;

    while (pasirinkimas != 6) {

        cout << "\n1. vardo, pavardes ivedimas" << endl;
        cout << "2. rezultatai" << endl;
        cout << "3. skaitymas is failo" << endl;
        cout << "4. failu generavimas" << endl;
        cout << "5. isvalyti sarasa" << endl;
        cout << "6. isejimas is programos" << endl;
        cout << "pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore();

        if (pasirinkimas == 1) {

            cout << "" << endl;
            cout << "ivesk savo varda:" << endl;
            cin >> vardas;
            cout << "ivesk savo pavarde:" << endl;
            cin >> pavarde;
            cin.ignore();
            cout << "ar zinai savo nd ir egzo rezultatus? jei ne, galima atsitiktinai sugeneruot (Y/N)" << endl;
            cin >> aware;
            cin.ignore();

            vector<int> ndpazymiai;

            if (aware == "Y") {
                ndpazymiai = ndloop();
                cout << "kiek gavai is egzamino?:" << endl;
                cin >> egzrezultatas;
            } else {
                ndpazymiai = randomgrades();
                egzrezultatas = 1 + (rd() % 10);
            }

            studentas s;
            s.vardas = vardas;
            s.pavarde = pavarde;
            s.ndpazymiai = ndpazymiai;
            s.egzrezultatas = egzrezultatas;
            s.rezvidurkis = vidurkiscalc(ndpazymiai, egzrezultatas);
            s.rezmedian = mediancalc(ndpazymiai, egzrezultatas);
            visistudentai.push_back(s);

        }

        else if (pasirinkimas == 2) {
            
            sort(visistudentai.begin(), visistudentai.end(), lyginti);
            printHeader();
            for (auto s : visistudentai) {
            results(s);
        }

        }

        else if (pasirinkimas == 3) {
          
            vector<studentas> failoStudentai = fileread();
            for (auto s : failoStudentai) {
                visistudentai.push_back(s);
            }
        
        }

        else if (pasirinkimas == 4) {

            filegenerator();

        }

        else if (pasirinkimas == 5) {

            visistudentai.clear();
            cout << "sarasas isvalytas" << endl;

        }

        else if (pasirinkimas != 6) {

            cout << "bandyk vel" << endl;

        }

    }

    return 0;

}