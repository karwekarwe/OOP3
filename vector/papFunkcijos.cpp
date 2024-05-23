#include "vector.h"
#include "funkcijos.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>


using namespace std;

    
    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
     //   Vector<int>& namuDarbai = s.getNamuDarbai();
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
       // Vector<int>& namuDarbai = s.getNamuDarbai();

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

void testai(){

        // constructor
    Vector<int> nd = {1, 2, 3};
    std::string vardas = "John";
    std::string pavarde = "Doe";
    Stud s2(nd, vardas, pavarde, 3, 3.3, 3);
    //Stud s2(vardas, pavarde);
    assert(s2.getVardas() == "John");
    assert(s2.getPavarde() == "Doe");
    assert(s2.getNamuDarbai() == nd);
    assert(s2.getEgzaminas() == 3);
    assert(s2.getGal() == 3.3);
    assert(s2.getNdcount() == 3);

        // copy contruct
    Stud s3 = s2;
    assert(s3.getVardas() == "John");
    assert(s3.getPavarde() == "Doe");
    assert(s3.getNamuDarbai() == nd);
    assert(s3.getEgzaminas() == 3);
    assert(s3.getGal() == 3.3);
    assert(s3.getNdcount() == 3);


        // move constr

    Stud s4 = std::move(s3);
    assert(s4.getVardas() == "John");
    assert(s4.getPavarde() == "Doe");
    assert(s4.getNamuDarbai() == nd);
    assert(s4.getEgzaminas() == 3);
    assert(s4.getGal() == 3.3);
    assert(s4.getNdcount() == 3);

    assert(s3.getVardas().empty());
    assert(s3.getPavarde().empty());
    assert(s3.getNamuDarbai().empty());
    assert(s3.getEgzaminas() == 0);
    assert(s3.getGal() == 0.0);
    assert(s3.getNdcount() == 0);

    cout << "Testai sekmingi" <<endl;
    }

void isvedimas_i_ekrana(const Vector<Stud>& luzeriukai, const Vector<Stud>& studentai) {
        cout << "Luzeriukai:" << endl;
    for (const auto& studentas : luzeriukai) {
            cout << studentas;
    }
    cout << "Intelektualai:" << endl;
    for (const auto& studentas : studentai) {
            cout << studentas;
    }
}


void isvedimas_i_faila(const Vector<Stud>& luzeriukai, const Vector<Stud>& studentai, const string& failPav) {
     ofstream outputFileUnder("luzeriukai " + failPav);
    if (!outputFileUnder.is_open()) {
        cerr << "Nepavyko sukurti naujo failo. outputFileUnder" << endl;
        return;
    }
    ofstream outputFileOver("intelektualai " + failPav);
    if (!outputFileOver.is_open()) {
        cerr << "Nepavyko sukurti naujo failo. outputFileOver" << endl;
        return;
    }
        for (const auto& studentas : luzeriukai){
            outputFileUnder << studentas;
        }   
        for (const auto& studentas : studentai){
            outputFileOver << studentas;
        } 

        outputFileUnder.close();
        outputFileOver.close();
    }

//Vector testai

void VectorTest() {

//pop
    int suma = 0;
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(15);
    v1.push_back(2);

     while (!v1.empty()) {  
        suma += v1.back();  
        v1.pop_back();      
    }

    cout<<"(pop) suma: " << suma <<endl;

//push
    Vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(15);
    v2.push_back(2);

    cout <<"(push) v susideda is: "<<endl;
    for (int i = 0; i < v2.size(); i++) {
        cout<<  v2[i] <<" ";
       
    }
 cout << '\n';

//shrink
     Vector<int> v3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        v3.reserve(20);
        cout << "(shrink) Talpa prieš shrink_to_fit: " << v3.capacity() << endl;
        v3.shrink_to_fit();
        cout << "(shrink) Talpa po shrink_to_fit: " << v3.capacity() << endl;

//begin
Vector<int> v4;
        for (int i = 1; i <= 5; i++) v4.push_back(i);

        cout << "(begin) v4 susideda iš:";
        for (Vector<int>::iterator it = v4.begin(); it != v4.end(); ++it)
        cout << ' ' << *it;
        cout << '\n';

//resize
Vector<int> v5;
        for (int i = 1; i < 10; i++) v5.push_back(i);

        v5.resize(5);
        v5.resize(8, 100);
        v5.resize(12);

        cout << "(resize) v5 susideda iš:";
        for (Vector<int>::size_type i = 0; i < v5.size(); i++)
            cout << ' ' << v5[i];
        cout << '\n';

}
//insert
void insertTest() {
    
    cout<<"insert:"<<endl;

    // i tuscia
    Vector<int> v1;
    v1.insert(v1.begin(), 10);
    cout << "10 iterpimas i tucia vektoriu: ";
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl; // 100

    // pradzioj
    Vector<int> v2 = {1, 2, 3, 4, 5};
    v2.insert(v2.begin(), 0);
    cout << "0 iterpimas i pradzia: ";
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << " ";
    }
    cout << endl; // 0 1 2 3 4 5

    // vidury
    Vector<int> v3 = {1, 2, 4, 5};
    v3.insert(v3.begin() + 2, 3);
    cout << "3 iterpimas vidury: ";
    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << " ";
    }
    cout << endl; //  1 2 3 4 5

    // pabaigoj
    Vector<int> v4 = {1, 2, 3, 4};
    v4.insert(v4.end(), 5);
    cout << "5 iterpimas pabaigoj: ";
    for (int i = 0; i < v4.size(); ++i) {
        cout << v4[i] << " ";
    }
    cout << endl; // 1 2 3 4 5

    // kelis
    Vector<int> v5 = {1, 3, 4};
    v5.insert(v5.begin() + 1, 2);
    v5.insert(v5.begin() + 4, 5);
    cout << "keli iterpimai: ";
    for (int i = 0; i < v5.size(); ++i) {
        cout << v5[i] << " ";
    }
    cout << endl; // 1 2 3 4 5
}

void vectorVsVector() {
    auto start = chrono::steady_clock::now();
    unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;
    int stdVector = 0;
    for (unsigned int i = 1; i <= sz; ++i) {
        v1.push_back(i);
        if (v1.capacity() == v1.size()) {
            ++stdVector;
        }
    }

    auto end = chrono::steady_clock::now();
    auto skirtumas = chrono::duration<double> (end - start).count();   
    cout << "std::vector užpildymas " << sz << " dydzio užėme: " << setprecision(8) << skirtumas << " sekundes" << endl; 
    cout << "std::vector atmintis buvo perskirstyta " << stdVector << " kartų" << endl;

    auto start1 = chrono::steady_clock::now();
    Vector<int> v2;
    int vectorx = 0;
    for (unsigned int i = 1; i <= sz; ++i) {
        v2.push_back(i);
        if (v2.capacity() == v2.size()) {
            ++vectorx;
        }
    }
                
    auto end1 = chrono::steady_clock::now();
    auto skirtumas1 = chrono::duration<double> (end1 - start1).count(); 
    cout << "Vector užpildymas " << sz << " dydzio užėme: " << setprecision(8) << skirtumas1 << " sekundes" << endl;   
    cout << "Vector atmintis buvo perskirstyta " << stdVector << " kartų" << endl;
}