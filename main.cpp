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


vector<studentas> fileread(){

    int filechoice;

    cout << "is kurio failo nori skaityti?" << endl;
    cout << "1. kursiokai.txt" << endl;
    cout << "2. 10k studentu" << endl;
    cout << "3. 100k studentu" << endl;
    cout << "4. 1m studentu" << endl;
    cout << "pasirinkimas" << endl;
    cin >> filechoice;

    string file = "kursiokai.txt";
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

    vector<studentas> visistudentai;
    string vardas;
    string pavarde;
    string aware;
    random_device rd;
    int egzrezultatas;
    int pasirinkimas = 0;

    while (pasirinkimas != 4) {

        cout << "\n1. vardo, pavardes ivedimas" << endl;
        cout << "2. rezultatai" << endl;
        cout << "3. skaitymas is failo" << endl;
        cout << "4. isejimas is programos" << endl;
        cout << "pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore();

        if (pasirinkimas == 1) {

            cout << "ivesk savo varda:" << endl;
            cin >> vardas;
            cout << "ivesk savo pavarde:" << endl;
            cin >> pavarde;
            cin.ignore();
            cout << "ar zinai savo nd ir egzo rezultatus? jei ne, galima atsitiktinai sugeneruot (Y/N)" << endl;
            cin >> aware;

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

            printHeader();
            for (auto s : visistudentai) {
        results(s);
        }
        }

        else if (pasirinkimas == 3){

            vector<studentas> failoStudentai = fileread();
            for (auto s : failoStudentai) {
                visistudentai.push_back(s);
            }

        }

        else if (pasirinkimas != 4) {

            cout << "bandyk vel" << endl;

        }

    }

    cout << "programa baigta" << endl;
    return 0;

}