#pragma once
#include <string>
#include <vector>
#include <list>
#include <algorithm>

struct studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> ndpazymiai;
    int egzrezultatas;
    double rezvidurkis;
    double rezmedian;
};

#ifdef USE_VECTOR
using konteineris = std::vector<studentas>;
#else
using konteineris = std::list<studentas>;
#endif // claude sugeneruota, kad galeciau atlikt greiciau benchmark'us

template <typename C, typename Cmp>
void rikiuoti(C& c, Cmp cmp){
    if constexpr (std::is_same_v<C, std::list<studentas>>){
        c.sort(cmp);
    } else {
        std::sort(c.begin(), c.end(), cmp);
    }
}