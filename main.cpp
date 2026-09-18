#include <iostream>
#include <vector>
#include <string>
#include <numeric>

struct {

} struktura;

int vidurkiscalc(std::vector<int> ndvektorius) {

    int suma = accumulate(ndvektorius.begin(), ndvektorius.end(), 0);
    double vidurkis = (double)suma / ndvektorius.size();

    return 0;
}

double galutinis(double vidurkis, double egzas){
    double galutinis = ((double)vidurkis * 0.4) + (egzas *0.6);
    return galutinis;
}


std::vector<int> ndloop(){
    
    std::vector<int> ndpazymiai = {};

    std::cout << "kokie namu darbu rezultatai?" << std::endl;
    std::cout << '(parasyk "-1", jei surasei visus pazymius)' << std::endl;

    while (true){
        int ndrezultatai;
        std::cin >> ndrezultatai;
        if (ndrezultatai == -1){
            break;
        } else {
            ndpazymiai.push_back(ndrezultatai);
        }
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

    std::vector<int> ndpazymiai = ndloop();
    vidurkiscalc(ndpazymiai);
    
    std::cout << "kiek gavai is egzamino?:" << std::endl;
    std::cin >> egzrezultatai;

    //funkcija publish results
}

