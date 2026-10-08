#include "rikiavimas.h"


bool lyginti(const studentas& a, const studentas& b){

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

    return lyginti(a, b);

}


bool pagalGalutini(const studentas& a, const studentas& b){

    return a.rezvidurkis < b.rezvidurkis;
    
}