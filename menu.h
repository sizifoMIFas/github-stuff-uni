#pragma once
#include "studentas.h"
#include <string> 
#include <utility>
#include <iostream>


void printHeader(std::ostream& out = std::cout);
void results(studentas s, std::ostream& out = std::cout);
std::string filechoice();
std::pair<int, int> rusiavimomenu();