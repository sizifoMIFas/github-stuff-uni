#include "grades.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;

vector<int> ndloop(){
    
    vector<int> ndpazymiai = {};

    cout << "kokie namu darbu rezultatai?" << endl;
    cout << "(paspausk enter kai baigei ivedinet pazymius)" << endl;

    while (true) {

        string line;
        getline(cin, line);

        if (line.empty()) {
            break;
        }

        int ndrezultatas = stoi(line); 
        ndpazymiai.push_back(ndrezultatas);
    } 
        
    return ndpazymiai; 

}

vector<int> randomgrades(){

    random_device rd;
    vector<int> ndpazymiai;

    for (int i = 0; i < 5; ++i) {
        ndpazymiai.push_back(1 + (rd() % 10));
    }

    return ndpazymiai;

}