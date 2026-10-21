#pragma once
#include <string>
#include <vector>
#include <list>

struct studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> ndpazymiai;
    int egzrezultatas;
    double rezvidurkis;
    double rezmedian;
};

using konteineris = std::list<studentas>;