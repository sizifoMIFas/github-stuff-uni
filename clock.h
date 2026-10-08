#pragma once
#include <chrono>

std::chrono::high_resolution_clock::time_point clockstart();
double clockend(std::chrono::high_resolution_clock::time_point start);