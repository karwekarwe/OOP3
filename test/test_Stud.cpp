#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../vector/student.h"

using namespace std;

TEST_CASE("Stud default constructor", "[Stud]") {
    Stud stud;
    REQUIRE(stud.getVardas() == "");
    REQUIRE(stud.getPavarde() == "");
    REQUIRE(stud.getEgzaminas() == 0);
    REQUIRE(stud.getGal() == 0);
    REQUIRE(stud.getNdcount() == 0);
    REQUIRE(stud.getNamuDarbai().size() == 0);
}

TEST_CASE("Stud parameterized constructor", "[Stud]") {
    vector<int> namuDarbai = {1, 2, 3};
    string vardas = "John";
    string pavarde = "Doe";
    Stud stud(namuDarbai, vardas, pavarde, 90, 3.5, 2);    
    REQUIRE(stud.getVardas() == "John");
    REQUIRE(stud.getPavarde() == "Doe");
    REQUIRE(stud.getEgzaminas() == 90);
    REQUIRE(stud.getGal() == 3.5);
    REQUIRE(stud.getNdcount() == 2);
    REQUIRE(stud.getNamuDarbai() == namuDarbai);
}

TEST_CASE("Stud copy constructor", "[Stud]") {
    vector<int> namuDarbai = {1, 2, 3};
    string vardas = "John";
    string pavarde = "Doe";
    Stud stud1(namuDarbai, vardas, pavarde, 90, 3.5, 2);
    Stud stud2(stud1);
    REQUIRE(stud2.getVardas() == "John");
    REQUIRE(stud2.getPavarde() == "Doe");
    REQUIRE(stud2.getEgzaminas() == 90);
    REQUIRE(stud2.getGal() == 3.5);
    REQUIRE(stud2.getNdcount() == 2);
    REQUIRE(stud2.getNamuDarbai() == namuDarbai);
}

TEST_CASE("Stud copy assignment operator", "[Stud]") {
    vector<int> namuDarbai = {1, 2, 3};
    string vardas = "John";
    string pavarde = "Doe";
    Stud stud1(namuDarbai, vardas, pavarde, 90, 3.5, 2);
    Stud stud2;
    stud2 = stud1;
    REQUIRE(stud2.getVardas() == "John");
    REQUIRE(stud2.getPavarde() == "Doe");
    REQUIRE(stud2.getEgzaminas() == 90);
    REQUIRE(stud2.getGal() == 3.5);
    REQUIRE(stud2.getNdcount() == 2);
    REQUIRE(stud2.getNamuDarbai() == namuDarbai);
}

TEST_CASE("Stud move constructor", "[Stud]") {
    vector<int> namuDarbai = {1, 2, 3};
    string vardas = "John";
    string pavarde = "Doe";
    Stud stud1(namuDarbai, vardas, pavarde, 90, 3.5, 2);
    Stud stud2(move(stud1));
    REQUIRE(stud2.getVardas() == "John");
    REQUIRE(stud2.getPavarde() == "Doe");
    REQUIRE(stud2.getEgzaminas() == 90);
    REQUIRE(stud2.getGal() == 3.5);
    REQUIRE(stud2.getNdcount() == 2);
    REQUIRE(stud2.getNamuDarbai() == namuDarbai);
}

TEST_CASE("Stud move assignment operator", "[Stud]") {
    vector<int> namuDarbai = {1, 2, 3};
    string vardas = "John";
    string pavarde = "Doe";
    Stud stud1(namuDarbai, vardas, pavarde, 90, 3.5, 2);
    Stud stud2;
    stud2 = std::move(stud1);
    REQUIRE(stud2.getVardas() == "John");
    REQUIRE(stud2.getPavarde() == "Doe");
    REQUIRE(stud2.getEgzaminas() == 90);
    REQUIRE(stud2.getGal() == 3.5);
    REQUIRE(stud2.getNdcount() == 2);
    REQUIRE(stud2.getNamuDarbai() == namuDarbai);
}