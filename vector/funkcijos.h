#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "vector.h"
#include "student.h"

bool rusiavimas(const Stud& a, const Stud& b, char metPas);
double vidurkis(Stud&);
double mediana(Stud&);
void isFailo(const std::string& failPav, Vector<Stud>& studentai, int dyd);
void failuGen(const std::string& failPav, int numRecords);
void rusiavimasGen(const std::string& failPav, Vector<Stud>& studentai, Vector<Stud>& luzeriukai);
void ranka(Vector<Stud>& studentai);
bool rusiavimasV(const Stud& a, const Stud& b);
bool rusiavimasP(const Stud& a, const Stud& b);
bool rusiavimasG(const Stud& a, const Stud& b);
void testai();
void isvedimas_i_ekrana(const Vector<Stud>& luzeriukai, const Vector<Stud>& studentai);
void isvedimas_i_faila(const Vector<Stud>& luzeriukai, const Vector<Stud>& studentai, const string& failPav);
void VectorTest();
void insertTest();


#endif 
