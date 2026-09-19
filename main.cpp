#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
using namespace std;


struct studentas {

    string vardas;
    string pavarde;
    vector<int> ndpazymiai;
    int egzrezultatas;
    double rezvidurkis;
    double rezmedian;

};


double vidurkiscalc(vector<int> ndvektorius) {

    int suma = accumulate(ndvektorius.begin(), ndvektorius.end(), 0);
    double vidurkis = (double)suma / ndvektorius.size();

    return vidurkis;

}

double mediancalc(vector<int> ndvektorius){
    double median;

    sort(ndvektorius.begin(), ndvektorius.end());
        //kai nelyginis, imi vidurini
        if (ndvektorius.size() % 2 == true){
            double median = ndvektorius[ndvektorius.size() / 2];
        } else { // kai lyginis vektorius, randi du vidurinius indexus ir gauni vidurki is ju
            int upper = (ndvektorius.size() / 2);
            int lower = ((ndvektorius.size() / 2) - 1);
            double median = ((ndvektorius[upper] + ndvektorius[lower]) / 2.0);
        } 

    return median;

}


double galutinis(double vidurkis, double egzas){

    double galutinis = ((double)vidurkis * 0.4) + (egzas * 0.6);
    return galutinis;

}


void results(studentas s){

    cout << fixed << setprecision(2);

    cout << left
    << setw(16) << "Vardas"
    << setw(16) << "Pavarde"
    << setw(16) << "Galutinis (vid)" 
    << setw(16) << "Galutinis (med)" << endl;

    cout << left
    << setw(16) << s.vardas
    << setw(16) << s.pavarde
    << setw(16) << s.rezvidurkis
    << setw(16) << s.rezmedian << endl;

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


int main(){

    string vardas;
    string pavarde;

    int egzrezultatai;

    cout << "ivesk savo varda:" << endl;
    cin >> vardas;
    cout << "ivesk savo pavarde:" << endl;
    cin >> pavarde;
    cin.ignore();
    //"kiek gavai is nd?" etc
    vector<int> ndpazymiai = ndloop();
    vidurkiscalc(ndpazymiai);
    // medianacalc(ndpazymiai);

    cout << "kiek gavai is egzamino?:" << endl;
    cin >> egzrezultatai;

    studentas s;
    s.vardas = vardas;
    s.pavarde = pavarde;
    s.ndpazymiai = ndpazymiai;
    s.egzrezultatas = egzrezultatai;
    s.rezvidurkis = vidurkiscalc(ndpazymiai);
    s.rezmedian = mediancalc(ndpazymiai); 

    results(s);

}

