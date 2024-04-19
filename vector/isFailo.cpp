#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <cstdlib> 
#include <algorithm>



#include "student.h"
#include "funkcijos.h"


using namespace std;
extern chrono::milliseconds totalTime;

void isFailo(const string& failPav, vector<Stud>& studentai, int dyd) {
    Stud naujasS;
    auto startSkaitymas = chrono::steady_clock::now();

    try {
        ifstream failas(failPav);
        if (!failas) {
            throw runtime_error("Nepavyko atidaryti failo. isF");
        }

        string line;
        getline(failas, line); 

        int baluCount = 0;

        stringstream headerS(line);
        string headerItem;

    
        while (headerS >> headerItem) {
            baluCount++;
        }
        baluCount -= 3; 
       
        studentai.reserve(dyd); 

        vector<string> lines;  
        lines.reserve(dyd);    

        // Read file line by line
        while (getline(failas, line)) {
            lines.push_back(line);

            // Process lines in chunks
            if (lines.size() >= dyd) { 
              

                for (const auto& bufferedLine : lines) {
                    stringstream stringBuferis(bufferedLine);

                    string tempV, tempP;
                    int tempE;
                    vector<int> tempND;

                    stringBuferis >> tempV >> tempP;
                    naujasS.setVardas(tempV);
                    naujasS.setPavarde(tempP);

                    // Clear the existing grades
                    naujasS.clearND();

                    for (int i = 0; i < baluCount; ++i) {
                        int balas;
                        stringBuferis >> balas;
                        naujasS.addND(balas);
                    }

                    stringBuferis >> tempE;
                    naujasS.setEgzaminas(tempE);

                    studentai.push_back(naujasS);
                }

                // Clear buffer
                lines.clear();
            }
        }

        // Process remaining lines
        for (const auto& remainingLine : lines) {
            stringstream stringBuferis(remainingLine);

            string tempV, tempP;
            int tempE;
            vector<int> tempND;

            stringBuferis >> tempV >> tempP;
            naujasS.setVardas(tempV);
            naujasS.setPavarde(tempP);

            // Clear the existing grades
            naujasS.clearND();

            for (int i = 0; i < baluCount; ++i) {
                int balas;
                stringBuferis >> balas;
                naujasS.addND(balas);
            }

            stringBuferis >> tempE;
            naujasS.setEgzaminas(tempE);

            studentai.push_back(naujasS);
        }

        failas.close();
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    auto endSkaitymas = chrono::steady_clock::now(); 
    auto elapsedSkaitymas = chrono::duration_cast<chrono::milliseconds>(endSkaitymas - startSkaitymas);
    cout << failPav << "  Skaitymas uztruko: " << elapsedSkaitymas.count() << " milisekundes" << endl;
totalTime += elapsedSkaitymas;
 

char pasirinkimas;
while (true) {
    try {
        cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
        cin >> pasirinkimas;
        
        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            for (auto& studentas : studentai) {
                studentas.setGal(vidurkis(studentas)); // galutinis i struct
            }
            break;
        } else if (pasirinkimas == 'M' || pasirinkimas == 'm') {
            for (auto& studentas : studentai) {
                studentas.setGal(mediana(studentas)); // galutinis i struct
            }
            break;
        } else {
            throw invalid_argument("Neteisinga įvestis.");
        }
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}
    

}


