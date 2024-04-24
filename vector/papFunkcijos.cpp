#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    
    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
     //   vector<int>& namuDarbai = s.getNamuDarbai();
        for (int balas : s.getNamuDarbai()) {
            suma+= balas;
        }
        avg = suma / s.getNamuDarbai().size();
        
        gal = avg*0.4 + s.getEgzaminas()*0.6;

        return gal;
    }

        double mediana (Stud& s) {
        double med = 0;
        double gal;
       // vector<int>& namuDarbai = s.getNamuDarbai();

        sort(s.getNamuDarbai().begin(), s.getNamuDarbai().end());

        if (s.getNamuDarbai().size() % 2 == 0) {
            med = (s.getNamuDarbai()[s.getNamuDarbai().size() / 2 - 1] + s.getNamuDarbai()[s.getNamuDarbai().size() / 2]) / 2.0;
        }
        else {
            med = s.getNamuDarbai()[s.getNamuDarbai().size() / 2];
        }
        gal = med*0.4 + s.getEgzaminas()*0.6;

        return gal;
    }

    bool rusiavimasV(const Stud& a, const Stud& b) {
        return a.getVardas() < b.getVardas();
    }
    bool rusiavimasP(const Stud& a, const Stud& b) {
        return a.getPavarde() < b.getPavarde();
    }
    bool rusiavimasG(const Stud& a, const Stud& b) {
        return a.getGal() > b.getGal();
    }

