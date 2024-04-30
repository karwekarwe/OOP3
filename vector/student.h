#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stud {
private:
    string vardas_, pavarde_;
    int egzaminas_;
    double gal_;
    vector<int> namuDarbai_;
public:
    Stud() : egzaminas_(0), gal_(0) { }  // default konstruktorius
    Stud(vector <int>& namuDarbai, string& vardas, string& pavarde, int egzaminas, double gal)
        : namuDarbai_(namuDarbai), vardas_(vardas), pavarde_(pavarde), egzaminas_(egzaminas), gal_(gal) {}

    ~Stud() {}

    // Copy constructor
    Stud(const Stud& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_),  egzaminas_(other.egzaminas_),  gal_(other.gal_),  namuDarbai_(other.namuDarbai_) {}

    // Copy assignment operator
    Stud& operator=(const Stud& other) {// copy assignment
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egzaminas_ = other.egzaminas_;
            gal_ = other.gal_;
            namuDarbai_ = other.namuDarbai_;    
        }
        return *this;
    }

    // Move constructor
    Stud(Stud&& other) noexcept // move constructor
        : vardas_(move(other.vardas_)), pavarde_(move(other.pavarde_)), egzaminas_(other.egzaminas_), gal_(other.gal_), namuDarbai_(move(other.namuDarbai_)) {}

    // Move assignment operator

    Stud& operator=(Stud&& other) noexcept { // move assignment
        if (this != &other) {
            vardas_ = move(other.vardas_);
            pavarde_ = move(other.pavarde_);
            egzaminas_ = move(other.egzaminas_);
            gal_ = move(other.gal_);
            namuDarbai_ = move(other.namuDarbai_);
        }
        return *this;
    }



    // getteriai
    vector <int> getNamuDarbai() const {return namuDarbai_;}
    string getVardas() const {return vardas_;}
    string getPavarde() const {return pavarde_;}
    int getEgzaminas() const {return egzaminas_;}
    double getGal() const {return gal_;}

    //setteriai
    void setNamuDarbai(const vector <int>& namuDarbai) {namuDarbai_ = namuDarbai;}
    void setVardas(const string& vardas) {vardas_ = vardas;}
    void setPavarde(const string& pavarde) {pavarde_ = pavarde;}
    void setEgzaminas (int egzaminas) {egzaminas_ = egzaminas;}
    void setGal (double gal) {gal_ = gal;}

    //kiti
    void addND(int namuDarbai) { namuDarbai_.push_back(namuDarbai); }
    void clearND() { namuDarbai_.clear(); }

};




#endif
