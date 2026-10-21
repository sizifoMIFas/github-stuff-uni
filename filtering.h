#pragma once
#include <string>
#include <vector>
#include <utility>
#include "studentas.h"

std::pair<konteineris, konteineris> studentsplit(const konteineris& visistudentai);
void gradedfiles(const konteineris& nerdai, const konteineris& nelaimingi, std::string pavadinimas);
void rusiavimoinfo(int rusiavimas, std::string paskutinisfailas, const konteineris& visistudentai);