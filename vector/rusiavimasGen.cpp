#include "vector.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <iterator>


#include "student.h"
#include "funkcijos.h"

using namespace std;
extern chrono::milliseconds totalTime;


void rusiavimasGen(const string& failPav, Vector<Stud>& studentai, Vector<Stud>& luzeriukai) {

    auto startRus = chrono::steady_clock::now();


    // Manually copying elements that match the condition
    for (auto it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->getGal() < 5.0) {
            luzeriukai.push_back(*it);
        }
    }

    // Erasing elements that match the condition
    auto new_end = std::remove_if(studentai.begin(), studentai.end(), [](const Stud& student) {
        return student.getGal() < 5.0;
    });
    studentai.erase(new_end, studentai.end());


            auto endRus = chrono::steady_clock::now(); 
            auto elapsedRus = chrono::duration_cast<chrono::milliseconds>(endRus - startRus);
            cout  << failPav << "Studentu skirstymo  i dvi grupes uztruko: " << elapsedRus.count() << " milisekundes" << endl;
    totalTime += elapsedRus;

        


        char rusPas;

             
                cout << "Pasirinkite rikiavimo metoda (1 - vardas, 2 - pavarde, 3 - galutinis):" << endl;
                cin >> rusPas;
                auto startIsved = chrono::steady_clock::now(); 

                if (rusPas == '1') {
                    sort(studentai.begin(), studentai.end(), rusiavimasV);
                    sort(luzeriukai.begin(), luzeriukai.end(), rusiavimasV);
                } else if (rusPas == '2') {
                    sort(studentai.begin(), studentai.end(), rusiavimasP);
                    sort(luzeriukai.begin(), luzeriukai.end(), rusiavimasP);
                } else if (rusPas == '3') {
                    sort(studentai.begin(), studentai.end(), rusiavimasG);
                    sort(luzeriukai.begin(), luzeriukai.end(), rusiavimasG);
                }


            auto endIsved = chrono::steady_clock::now(); 
            auto elapsedIsved = chrono::duration_cast<chrono::milliseconds>(endIsved - startIsved);
            cout << failPav << "Studentu rusiavimas didejimo tvarka konteineryje (funkcija sort) uztruko: " << elapsedIsved.count() << "  milisekundes" << endl;
    
               totalTime += elapsedIsved;


}