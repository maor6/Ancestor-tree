#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;

Tree T ("X");

TEST_CASE("test build family tree") {
    T.addFather("X", "Yoni");
    T.addMother("X", "Noa");
    T.addFather("Yoni", "Ziv");
    T.addMother("Yoni", "Yael");
    T.addFather("Noa", "Ron");
    T.addMother("Noa", "Maly");
    T.addFather("Ziv", "Gil");
    T.addMother("Gil", "Gali");
    T.addFather("Gil", "Gil");
    T.addMother("Maly", "Shir");
    T.addFather("Maly", "Shalom");
    CHECK(T.getroot()->father->name == string("Yoni"));
    CHECK(T.getroot()->mother->name == string("Noa"));
    CHECK(T.getroot()->father->father->name == string("Ziv"));
    CHECK(T.getroot()->father->mother->name == string("Yael"));
    CHECK(T.getroot()->mother->father->name == string("Ron"));
    CHECK(T.getroot()->mother->mother->name == string("Maly"));
    CHECK(T.getroot()->father->father->father->name == string("Gil"));
    CHECK(T.getroot()->father->father->mother->name == string("Gali"));
    CHECK(T.getroot()->father->father->father->father->name == string("Gil"));
    CHECK(T.getroot()->mother->mother->mother->name == string("Shir"));
    CHECK(T.getroot()->mother->mother->father->name == string("Shalom"));
    CHECK(T.getroot()->father->father->father->father->father == NULL);
    CHECK_THROWS(T.addFather("Yoni", "A")); // Y had a father already
    CHECK_THROWS(T.addMother("Yoni", "libi")); // Y had a mother already
    CHECK_THROWS(T.addFather("B", "C")); // B not exist in the tree
    CHECK_THROWS(T.addMother("B", "C")); // B not exist in the tree
}//16

TEST_CASE("test find function") {
    CHECK(T.find("father") == string("Yoni"));
    CHECK(T.find("mother") == string("Noa"));
    CHECK(T.find("grandfather") == string("Ziv") || T.find("grandfather") == string("Ron"));
    CHECK(T.find("grandmother")== string("Yael") || T.find("grandmother")== string("Maly"));
    CHECK(T.find("great-grandfather") == string("Gil") || T.find("great-grandfather") == string("gali"));
    CHECK(T.find("great-grandmother") == string("Shalom") || T.find("great-grandfather") == string("Shir"));
    CHECK(T.find("great-great-grandfather") == string("Gil"));
    CHECK_THROWS(T.find("great-great-grandmother"));// not exist in the tree
    CHECK_THROWS(T.find("great")); // invalid word
    CHECK_THROWS(T.find("great-great-great-grandfather"));
} // 10

TEST_CASE("test relation function") {
    CHECK(T.relation("Yoni") == string("father"));
    CHECK(T.relation("Noa") == string("mother"));
    CHECK(T.relation("Ziv") == string("grandfather"));
    CHECK(T.relation("Ron") == string("grandfather"));
    CHECK(T.relation("Yael") == string("grandmother"));
    CHECK(T.relation("Maly") == string("grandmother"));
    CHECK(T.relation("Gil") == string("great-grandfather") || 
            T.relation("Gil") == string("great-great-grandfather"));
    CHECK(T.relation("Gali") == string("great-grandfather"));
    CHECK(T.relation("Shalom") == string("great-grandmother"));
    CHECK(T.relation("Shir") == string("great-grandmother"));
    CHECK(T.relation("Yonit") == string("unrelated"));
}//11

