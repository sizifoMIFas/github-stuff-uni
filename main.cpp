#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

struct studentas {

    std::string vardas;
    std::string pavarde;
    std::vector<int> ndpazymiai;
    int egzrezultatas;
    double rezvidurkis;
    double rezmedian;

};


double vidurkiscalc(std::vector<int> ndvektorius) {

    int suma = accumulate(ndvektorius.begin(), ndvektorius.end(), 0);
    double vidurkis = (double)suma / ndvektorius.size();
    return vidurkis;

}


double galutinis(double vidurkis, double egzas){

    double galutinis = ((double)vidurkis * 0.4) + (egzas * 0.6);
    return galutinis;

}


void results(studentas s){

    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::left
    << std::setw(12) << "vardas"
    << std::setw(12) << "pavarde"
    << std::setw(12) << "rezvidurkis" << std::endl;

    std::cout << std::left
    << std::setw(12) << s.vardas
    << std::setw(12) << s.pavarde
    << std::setw(12) << s.rezvidurkis << std::endl;

}


std::vector<int> ndloop(){
    
    std::vector<int> ndpazymiai = {};

    std::cout << "kokie namu darbu rezultatai?" << std::endl;
    std::cout << "(paspausk enter kai baigei ivedinet pazymius)" << std::endl;

    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        int ndrezultatas = std::stoi(line);
        ndpazymiai.push_back(ndrezultatas);
        } return ndpazymiai;

}


int main(){

    std::string vardas;
    std::string pavarde;
    std::string fullname = vardas + pavarde;

    int egzrezultatai;

    std::cout << "ivesk savo varda:" << std::endl;
    std::cin >> vardas;
    std::cout << "ivesk savo pavarde:" << std::endl;
    std::cin >> pavarde;
    std::cin.ignore();
    //"kiek gavai is nd?" etc
    std::vector<int> ndpazymiai = ndloop();
    vidurkiscalc(ndpazymiai);

    std::cout << "kiek gavai is egzamino?:" << std::endl;
    std::cin >> egzrezultatai;

    studentas s;
    s.vardas = vardas;
    s.pavarde = pavarde;
    s.ndpazymiai = ndpazymiai;
    s.egzrezultatas = egzrezultatai;
    s.rezvidurkis = vidurkiscalc(ndpazymiai);
    s.rezmedian = 0; 

    results(s);

}

