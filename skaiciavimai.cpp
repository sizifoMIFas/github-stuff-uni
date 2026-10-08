#include <vector>
#include <numeric>
#include <algorithm>
#include "skaiciavimai.h"


double galutinis(double vidurkis_or_median, double egzas){

    double galutinisvid = ((double)vidurkis_or_median * 0.4) + (egzas * 0.6);
    return galutinisvid;

}


double vidurkiscalc(std::vector<int> ndvektorius, int examgrade){

if (ndvektorius.empty()){
    return galutinis(0, examgrade);
}

    int suma = accumulate(ndvektorius.begin(), ndvektorius.end(), 0);
    double vidurkis = (double)suma / ndvektorius.size();
    double galutinisvid = galutinis(vidurkis, examgrade);
    
    return galutinisvid;

}


double mediancalc(std::vector<int> ndvektorius, int examgrade){

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