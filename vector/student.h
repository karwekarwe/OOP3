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
    double galv_, galm_;
    vector<int> namuDarbai_;
public:
    Stud() : egzaminas_(0) { }  // default konstruktorius
    Stud(const vector <int>& namuDarbai, const string& vardas, const string& pavarde, int egzaminas, double galv, double galm)
        : namuDarbai_(namuDarbai), vardas_(vardas), pavarde_(pavarde), egzaminas_(egzaminas), galv_(galv), galm_(galm) {}

    ~Stud() {}

    const vector <int>& getNamuDarbai() const {return namuDarbai_;}
    const string& getVardas() const {return vardas_;}
    const string& getPavarde() const {return pavarde_;}
    int getEgzaminas() const {return egzaminas_;}
    double getGalv() const {return galv_;}
    double getGalm() const {return galm_;}

    void setNamuDarbai(const vector <int>& namuDarbai) {namuDarbai_ = namuDarbai;}
    void setVardas(const string& vardas) {vardas_ = vardas;}
    void setPavarde(const string& pavarde) {pavarde_ = pavarde;}
    void setEgzaminas (int egzaminas) {egzaminas_ = egzaminas;}
    void setGalv (double galv) {galv_ = galv;}
    void setGalm (double galm) {galm_ = galm;}


};




#endif
