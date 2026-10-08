#pragma once
#include <string>
#include <vector>
#include <utility>
#include "studentas.h"

std::pair<std::vector<studentas>, std::vector<studentas>> studentsplit(const std::vector<studentas>& visistudentai);
void gradedfiles(const std::vector<studentas>& nerdai, const std::vector<studentas>& nelaimingi, std::string pavadinimas);
void rusiavimoinfo(int rusiavimas, std::string paskutinisfailas, const std::vector<studentas>& visistudentai);