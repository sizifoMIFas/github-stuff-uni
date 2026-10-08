#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;


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


double galutinis(double vidurkis_or_median, double egzas){

    double galutinisvid = ((double)vidurkis_or_median * 0.4) + (egzas * 0.6);
    return galutinisvid;

}


double vidurkiscalc(vector<int> ndvektorius, int examgrade){

if (ndvektorius.empty()){
    return galutinis(0, examgrade);
}

    int suma = accumulate(ndvektorius.begin(), ndvektorius.end(), 0);
    double vidurkis = (double)suma / ndvektorius.size();
    double galutinisvid = galutinis(vidurkis, examgrade);
    
    return galutinisvid;

}


double mediancalc(vector<int> ndvektorius, int examgrade){

if (ndvektorius.empty()){
    return galutinis(0, examgrade);
}

    double median;

    sort(ndvektorius.begin(), ndvektorius.end());
        
        if (ndvektorius.size() % 2 == true){
            median = ndvektorius[ndvektorius.size() / 2];
        } 
        
        else { 
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
    } 
        
    return ndpazymiai; 

}


bool lyginti(studentas a, studentas b){

    if (a.pavarde != b.pavarde) {
        return a.pavarde < b.pavarde;
    }
    return a.vardas < b.vardas;

}


bool pagalVarda(const studentas& a, const studentas& b){

    if (a.vardas != b.vardas) {
        return a.vardas < b.vardas;
    }
    return a.pavarde < b.pavarde;

}


bool pagalPavarde(const studentas& a, const studentas& b){

    if (a.pavarde != b.pavarde) {
        return a.pavarde < b.pavarde;
    }
    return a.vardas < b.vardas;

}


bool pagalGalutini(const studentas& a, const studentas& b){

    return a.rezvidurkis < b.rezvidurkis;
    
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


auto studentsplit(const vector<studentas>& visistudentai){

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


auto clockstart(){

    auto start = high_resolution_clock::now();
    return start;

}


double clockend(high_resolution_clock::time_point start){
    
    auto end = high_resolution_clock::now();
    auto laikas = duration<double>(end - start);
    return laikas.count();
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


int main(){

    srand(time(0));
    vector<studentas> visistudentai;
    string vardas;
    string pavarde;
    string aware;
    random_device rd;
    int egzrezultatas;
    int pasirinkimas = 0;
    string paskutinisfailas;

    while (pasirinkimas != 6){

        cout << "\n1. vardo, pavardes ivedimas" << endl;
        cout << "2. rezultatai" << endl;
        cout << "3. skaitymas is failo" << endl;
        cout << "4. failu generavimas" << endl;
        cout << "5. isvalyti sarasa" << endl;
        cout << "6. isejimas is programos" << endl;
        cout << "pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore();

        if (pasirinkimas == 1){

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

        else if (pasirinkimas == 2){

            string choice;

            sort(visistudentai.begin(), visistudentai.end(), lyginti);
            printHeader();
            for (auto s : visistudentai) {
            results(s);
            }

            while (choice != "Y" && choice != "N"){
                cout << "" << endl;
                cout << "ar suskirstyti mokinius pagal rezultatus (0-5; 5-10)? (Y/N)" << endl;
                cout << "(bus sugeneruoti du failai)" << endl;
                cout << "pasirinkimas:" << endl;
                cin >> choice;
            
                if (choice == "Y"){
                int rusiavimas = rusiavimomenu();
                rusiavimoinfo(rusiavimas, paskutinisfailas, visistudentai);
                }

                else if (choice != "N"){               
                    cout << "error" << endl;
                }
            }
            visistudentai.clear();
        }

        else if (pasirinkimas == 3){

            string file = filechoice();
            paskutinisfailas = file;
            
            auto t = clockstart();
            vector<studentas> failoStudentai = fileread(file);
            cout << "failas nuskaitytas per: " << clockend(t) << " sekundes" << endl;
            for (auto s : failoStudentai) {
                visistudentai.push_back(s);
            }
        }

        else if (pasirinkimas == 4){

            cout << "" << endl;
            cout << "generuojami failai..." << endl;
            auto t = clockstart();
            filegenerator();
            cout << "failai sugeneruoti per: " << clockend(t) << " sekundes" << endl;
        }

        else if (pasirinkimas == 5){
            visistudentai.clear();
            cout << "sarasas isvalytas" << endl;
        }

        else if (pasirinkimas != 6){
            cout << "" << endl;
            cout << "error! bandyk vel" << endl;
        }
    }

    return 0;

}
