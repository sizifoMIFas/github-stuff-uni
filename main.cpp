#include <iostream>
#include <random>
#include "studentas.h"
#include "clock.h"
#include "skaiciavimai.h"
#include "rikiavimas.h"
#include "menu.h"
#include "grades.h"
#include "generators.h"
#include "reading.h"
#include "filtering.h"
using namespace std;


int main(){

    srand(time(0));
    vector<studentas> visistudentai;
    string vardas;
    string pavarde;
    string aware;
    random_device rd;
    int egzrezultatas;
    int pasirinkimas = 0;
    string paskutinisfailas;

    while (pasirinkimas != 6){

        cout << "\n1. vardo, pavardes ivedimas" << endl;
        cout << "2. rezultatai" << endl;
        cout << "3. skaitymas is failo" << endl;
        cout << "4. failu generavimas" << endl;
        cout << "5. isvalyti sarasa" << endl;
        cout << "6. isejimas is programos" << endl;
        cout << "pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore();

        if (pasirinkimas == 1){

            cout << "" << endl;
            cout << "ivesk savo varda:" << endl;
            cin >> vardas;
            cout << "ivesk savo pavarde:" << endl;
            cin >> pavarde;
            cin.ignore();
            cout << "ar zinai savo nd ir egzo rezultatus? jei ne, galima atsitiktinai sugeneruot (Y/N)" << endl;
            cin >> aware;
            cin.ignore();

            vector<int> ndpazymiai;

            if (aware == "Y") {
                ndpazymiai = ndloop();
                cout << "kiek gavai is egzamino?:" << endl;
                cin >> egzrezultatas;
            } else {
                ndpazymiai = randomgrades();
                egzrezultatas = 1 + (rd() % 10);
            }

            studentas s;
            s.vardas = vardas;
            s.pavarde = pavarde;
            s.ndpazymiai = ndpazymiai;
            s.egzrezultatas = egzrezultatas;
            s.rezvidurkis = vidurkiscalc(ndpazymiai, egzrezultatas);
            s.rezmedian = mediancalc(ndpazymiai, egzrezultatas);
            visistudentai.push_back(s);
        }

        else if (pasirinkimas == 2){

            string choice;

            sort(visistudentai.begin(), visistudentai.end(), lyginti);
            printHeader();
            for (auto s : visistudentai) {
            results(s);
            }

            while (choice != "Y" && choice != "N"){
                cout << "" << endl;
                cout << "ar suskirstyti mokinius pagal rezultatus (0-5; 5-10)? (Y/N)" << endl;
                cout << "(bus sugeneruoti du failai)" << endl;
                cout << "pasirinkimas:" << endl;
                cin >> choice;
            
                if (choice == "Y"){
                int rusiavimas = rusiavimomenu();
                rusiavimoinfo(rusiavimas, paskutinisfailas, visistudentai);
                }

                else if (choice != "N"){               
                    cout << "error" << endl;
                }
            }
            visistudentai.clear();
        }

        else if (pasirinkimas == 3){

            string file = filechoice();
            paskutinisfailas = file;
            
            auto t = clockstart();
            vector<studentas> failoStudentai = fileread(file);
            cout << "failas nuskaitytas per: " << clockend(t) << " sekundes" << endl;
            for (auto s : failoStudentai) {
                visistudentai.push_back(s);
            }
        }

        else if (pasirinkimas == 4){

            cout << "" << endl;
            cout << "generuojami failai..." << endl;
            auto t = clockstart();
            filegenerator();
            cout << "failai sugeneruoti per: " << clockend(t) << " sekundes" << endl;
        }

        else if (pasirinkimas == 5){
            visistudentai.clear();
            cout << "sarasas isvalytas" << endl;
        }

        else if (pasirinkimas != 6){
            cout << "" << endl;
            cout << "error! bandyk vel" << endl;
        }
    }

    return 0;

}
