#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../vector/vector.h"

using namespace std;

TEST_CASE("Vector default constructor", "[vector]") {
    Vector<int> vec;
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() == 0);
    REQUIRE(vec.empty());
}

TEST_CASE("Vector fill constructor", "[vector]") {
    Vector<int> vec(5, 10);
    REQUIRE(vec.size() == 5);
    REQUIRE(vec.capacity() == 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        REQUIRE(vec[i] == 10);
    }
}

TEST_CASE("Vector copy constructor", "[vector]") {
    Vector<int> vec1(5, 10);
    Vector<int> vec2 = vec1;
    REQUIRE(vec2.size() == vec1.size());
    REQUIRE(vec2.capacity() == vec1.capacity());
    for (size_t i = 0; i < vec2.size(); ++i) {
        REQUIRE(vec2[i] == vec1[i]);
    }
}

TEST_CASE("Vector move constructor", "[vector]") {
    Vector<int> vec1(5, 10);
    Vector<int> vec2 = std::move(vec1);
    REQUIRE(vec2.size() == 5);
    REQUIRE(vec2.capacity() == 5);
    REQUIRE(vec1.size() == 0);
    REQUIRE(vec1.capacity() == 0);
}

TEST_CASE("Vector copy assignment operator", "[vector]") {
    Vector<int> vec1(5, 10);
    Vector<int> vec2;
    vec2 = vec1;
    REQUIRE(vec2.size() == vec1.size());
    REQUIRE(vec2.capacity() == vec1.capacity());
    for (size_t i = 0; i < vec2.size(); ++i) {
        REQUIRE(vec2[i] == vec1[i]);
    }
}

TEST_CASE("Vector move assignment operator", "[vector]") {
    Vector<int> vec1(5, 10);
    Vector<int> vec2;
    vec2 = std::move(vec1);
    REQUIRE(vec2.size() == 5);
    REQUIRE(vec2.capacity() == 5);
    REQUIRE(vec1.size() == 0);
    REQUIRE(vec1.capacity() == 0);
}

TEST_CASE("Vector initializer list constructor", "[vector]") {
    Vector<int> vec = {1, 2, 3, 4, 5};
    REQUIRE(vec.size() == 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        REQUIRE(vec[i] == i + 1);
    }
}

TEST_CASE("Vector element access", "[vector]") {
    Vector<int> vec = {1, 2, 3, 4, 5};
    REQUIRE(vec[0] == 1);
    REQUIRE(vec[4] == 5);
    REQUIRE(vec.at(2) == 3);
    REQUIRE_THROWS_AS(vec.at(5), std::out_of_range);
}

TEST_CASE("Vector front and back access", "[vector]") {
    Vector<int> vec = {1, 2, 3, 4, 5};
    REQUIRE(vec.front() == 1);
    REQUIRE(vec.back() == 5);
}

TEST_CASE("Vector data access", "[vector]") {
    Vector<int> vec = {1, 2, 3, 4, 5};
    REQUIRE(*vec.data() == 1);
    REQUIRE(*(vec.data() + 4) == 5);
}

TEST_CASE("Vector resize", "[vector]") {
    Vector<int> vec(5, 10);
    vec.resize(3);
    REQUIRE(vec.size() == 3);
    vec.resize(7, 20);
    REQUIRE(vec.size() == 7);
    REQUIRE(vec[6] == 20);
}

TEST_CASE("Vector reserve and shrink_to_fit", "[vector]") {
    Vector<int> vec(5, 10);
    vec.reserve(10);
    REQUIRE(vec.capacity() == 10);
    vec.shrink_to_fit();
    REQUIRE(vec.capacity() == vec.size());
}

TEST_CASE("Vector push_back and pop_back", "[vector]") {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    REQUIRE(vec.size() == 3);
    REQUIRE(vec.back() == 3);
    vec.pop_back();
    REQUIRE(vec.size() == 2);
    REQUIRE(vec.back() == 2);
}

TEST_CASE("Vector clear", "[vector]") {
    Vector<int> vec = {1, 2, 3};
    vec.clear();
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.empty());
}

TEST_CASE("Vector insert and erase", "[vector]") {
    Vector<int> vec = {1, 2, 3};
    vec.insert(vec.begin() + 1, 4);
    REQUIRE(vec.size() == 4);
    REQUIRE(vec[1] == 4);
    vec.erase(vec.begin() + 1);
    REQUIRE(vec.size() == 3);
    REQUIRE(vec[1] == 2);
}

TEST_CASE("Vector swap", "[vector]") {
    Vector<int> vec1 = {1, 2, 3};
    Vector<int> vec2 = {4, 5, 6};
    vec1.swap(vec2);
    REQUIRE(vec1[0] == 4);
    REQUIRE(vec2[0] == 1);
}

TEST_CASE("Vector comparison operators", "[vector]") {
    Vector<int> vec1 = {1, 2, 3};
    Vector<int> vec2 = {1, 2, 3};
    Vector<int> vec3 = {4, 5, 6};
    REQUIRE(vec1 == vec2);
    REQUIRE(vec1 != vec3);
}

TEST_CASE("Vector erase_if", "[vector]") {
    Vector<int> vec = {1, 2, 3, 4, 5};
    erase_if(vec, [](int x) { return x % 2 == 0; });
    REQUIRE(vec.size() == 3);
    REQUIRE(vec[0] == 1);
    REQUIRE(vec[1] == 3);
    REQUIRE(vec[2] == 5);
}

TEST_CASE("Vector output operator", "[vector]") {
    Vector<int> vec = {1, 2, 3};
    std::stringstream ss;
    ss << vec;
    REQUIRE(ss.str() == "[1, 2, 3]");
}