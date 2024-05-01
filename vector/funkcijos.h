#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "student.h"

bool rusiavimas(const Stud& a, const Stud& b, char metPas);
double vidurkis(Stud&);
double mediana(Stud&);
void isFailo(const std::string& failPav, std::vector<Stud>& studentai, int dyd);
void failuGen(const std::string& failPav, int numRecords);
void rusiavimasGen(const std::string& failPav, std::vector<Stud>& studentai, vector<Stud>& luzeriukai);
void ranka(std::vector<Stud>& studentai);
bool rusiavimasV(const Stud& a, const Stud& b);
bool rusiavimasP(const Stud& a, const Stud& b);
bool rusiavimasG(const Stud& a, const Stud& b);
void testai();
void isvedimas_i_ekrana(const vector<Stud>& luzeriukai, const vector<Stud>& studentai);
void isvedimas_i_faila(const vector<Stud>& luzeriukai, const vector<Stud>& studentai, const string& failPav);

#endif 
