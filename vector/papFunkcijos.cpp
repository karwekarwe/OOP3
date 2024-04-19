#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    
    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
        const vector<int>& namuDarbai = s.getNamuDarbai();
        for (int balas : namuDarbai) {
            suma+= balas;
        }
        avg = suma / namuDarbai.size();
        
        gal = avg*0.4 + s.getEgzaminas()*0.6;

        return gal;
    }

        double mediana (Stud& s) {
        double med = 0;
        double gal;
        const vector<int>& namuDarbai = s.getNamuDarbai();
        sort(namuDarbai.begin(), namuDarbai.end());
        if (namuDarbai.size() % 2 == 0) {
            med = (namuDarbai[namuDarbai.size() / 2 - 1] + namuDarbai[namuDarbai.size() / 2]) / 2.0;
        }
        else {
            med = namuDarbai[namuDarbai.size() / 2];
        }
        gal = med*0.4 + s.getEgzaminas()*0.6;

        return gal;
    }

    bool rusiavimas(const Stud& a, const Stud& b, char metPas) {

try {
        metPas = toupper(metPas);

        if (metPas == 'V') {
            return a.getVardas() < b.getVardas();
        }
        else if (metPas == 'P') {
            return a.getPavarde() < b.getPavarde();
        }
        else if (metPas == 'G') {
            return a.getGal() < b.getGal();
        }
        else {
            throw std::invalid_argument("Neteisinga įvestis.");
        }
    } 
    catch (const std::invalid_argument& e) {
        cerr << e.what() << endl;
        return false;
    }
}
