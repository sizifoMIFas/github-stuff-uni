#pragma once
#include <string>
#include <vector>

using konteineris = std::vector<studentas>;

struct studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> ndpazymiai;
    int egzrezultatas;
    double rezvidurkis;
    double rezmedian;
};