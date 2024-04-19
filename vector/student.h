#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*struct Stud {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinis;
};*/

class Stud {
private:
    string vardas_, pavarde_;
    int egzaminas_;
    double gal_;
    vector<int> namuDarbai_;
public:
    Stud() : egzaminas_(0) { }  // default konstruktorius
    Stud(const vector <int>& namuDarbai, const string& vardas, const string& pavarde, int egzaminas, double gal)
        : namuDarbai_(namuDarbai), vardas_(vardas), pavarde_(pavarde), egzaminas_(egzaminas), gal_(gal) {}

    ~Stud() {}

    const vector <int>& getNamuDarbai() const {return namuDarbai_;}
    const string& getVardas() const {return vardas_;}
    const string& getPavarde() const {return pavarde_;}
    int getEgzaminas() const {return egzaminas_;}
    double getGal() const {return gal_;}

    void setNamuDarbai(const vector <int>& namuDarbai) {namuDarbai_ = namuDarbai;}
    void setVardas(const string& vardas) {vardas_ = vardas;}
    void setPavarde(const string& pavarde) {pavarde_ = pavarde;}
    void setEgzaminas (int egzaminas) {egzaminas_ = egzaminas;}
    void setGal (double gal) {gal_ = gal;}

};




#endif
