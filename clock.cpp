#include "clock.h"

using namespace std::chrono;

std::chrono::high_resolution_clock::time_point clockstart(){
    return high_resolution_clock::now();
}

double clockend(high_resolution_clock::time_point start){
    auto end = high_resolution_clock::now();
    auto laikas = duration<double>(end - start);
    return laikas.count();
}