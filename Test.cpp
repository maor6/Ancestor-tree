#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;

Tree R("Gohan");

TEST_CASE("test simple tree") {
    CHECK_NOTHROW(R.addFather("Gohan", "Goku"));
    CHECK_NOTHROW(R.addMother("Gohan", "Chichi"));
    CHECK_NOTHROW(R.addFather("Goku", "Bardok"));
    CHECK_NOTHROW(R.addMother("Goku", "Juhan"));
    CHECK_THROWS(R.addMother("Guko", "Bilbi")); // there is mother already
    CHECK(R.find("me") == string("Gohan"));
    CHECK(R.find("father") == string("Goku"));
    CHECK(R.find("mother") == string("Chichi"));
    CHECK(R.find("grandmother") == string("Juhan"));
    CHECK(R.find("grandfather") == string("Bardok"));
    CHECK(R.relation("Gohan") == string("me"));
    CHECK(R.relation("Chichi") == string("mother"));
    CHECK(R.relation("Goku") == string("father"));
    CHECK(R.relation("Bardok") == string("grandfather"));
    CHECK(R.relation("Juhan") == string("grandmother"));
    CHECK(R.relation("juhan") == string("unrelated"));
    CHECK_THROWS(R.find("great-grandmother"));
    CHECK_THROWS(R.find("Grandmother"));
    CHECK_THROWS(R.remove("juhan"));
    CHECK(R.remove("Juhan"));
    CHECK(R.relation("Juhan") == string("unrelated"));

}//21

Tree T("X");

TEST_CASE("test build family tree") {
    CHECK_NOTHROW(T.addFather("X", "Yoni"));
    CHECK_NOTHROW(T.addMother("X", "Noa"));
    CHECK_NOTHROW(T.addFather("Yoni", "Ziv"));
    CHECK_NOTHROW(T.addMother("Yoni", "Yael"));
    CHECK_NOTHROW(T.addFather("Noa", "Ron"));
    CHECK_NOTHROW(T.addMother("Noa", "Maly"));
    CHECK_NOTHROW(T.addFather("Ziv", "Gil"));
    CHECK_NOTHROW(T.addMother("Gil", "Gali"));
    CHECK_NOTHROW(T.addFather("Gil", "Gil"));
    CHECK_NOTHROW(T.addMother("Maly", "Shir"));
    CHECK_NOTHROW(T.addFather("Maly", "Shalom"));
    CHECK_NOTHROW(T.addMother("Shalom", "Shani"));
    CHECK_NOTHROW(T.addMother("Shani", "Shoham"));
    //CHECK(T.getroot() == string("X"));
    // CHECK(T.getroot()->father->name == string("Yoni"));
    // CHECK(T.getroot()->mother->name == string("Noa"));
    // CHECK(T.getroot()->father->father->name == string("Ziv"));
    // CHECK(T.getroot()->father->mother->name == string("Yael"));
    // CHECK(T.getroot()->mother->father->name == string("Ron"));
    // CHECK(T.getroot()->mother->mother->name == string("Maly"));
    // CHECK(T.getroot()->father->father->father->name == string("Gil"));
    // CHECK(T.getroot()->father->father->mother->name == string("Gali"));
    // CHECK(T.getroot()->father->father->father->father->name == string("Gil"));
    // CHECK(T.getroot()->mother->mother->mother->name == string("Shir"));
    // CHECK(T.getroot()->mother->mother->father->name == string("Shalom"));
    //CHECK(T.getroot()->father->father->father->father->father->name == NULL);
    CHECK_THROWS(T.addFather("Yoni", "A")); // Yoni had a father already
    CHECK_THROWS(T.addFather("X", "Ran"));
    CHECK_THROWS(T.addMother("Yoni", "libi")); // Yoni had a mother already
    CHECK_THROWS(T.addFather("B", "C")); // B not exist in the tree
    CHECK_THROWS(T.addMother("B", "C")); // B not exist in the tree
}//17

TEST_CASE("test find function") {
    CHECK(T.find("me") == string("X"));
    CHECK(T.find("father") == string("Yoni"));
    CHECK(T.find("mother") == string("Noa"));
    CHECK((T.find("grandfather") == string("Ziv") || T.find("grandfather") == string("Ron")));
    CHECK((T.find("grandmother")== string("Yael") || T.find("grandmother")== string("Maly")));
    CHECK((T.find("great-grandfather") == string("Gil") || T.find("great-grandfather") == string("Shalom")));
    CHECK(T.find("great-grandmother") == string("Shir"));
    CHECK(T.find("great-great-grandfather") == string("Gil"));
    CHECK((T.find("great-great-grandmother") == string("Shani") || T.find("great-great-grandmother") == string("Gali")));
    CHECK(T.find("great-great-great-grandmother") == string("Shoham"));
    CHECK_THROWS(T.find("great-great-great-grandfather"));// not exist in the tree
    CHECK_THROWS(T.find("FATHER"));// invalid word
    CHECK_THROWS(T.find("Me"));// invalid word
    CHECK_THROWS(T.find("great")); // invalid word
    CHECK_THROWS(T.find("great-grand"));// invalid word
    CHECK_THROWS(T.find("great grandfather"));// invalid word
    CHECK_THROWS(T.find("gread grandfather")); // invalid word
    CHECK_THROWS(T.find("great-great-great-grandfather"));// not exist in the tree
    CHECK_THROWS(T.find("uncle")); // not support
    CHECK_THROWS(T.find("brother")); // not support
    CHECK_THROWS(T.find("sister")); // not support
} // 21

TEST_CASE("test relation function") {
    CHECK(T.relation("Yoni") == string("father"));
    CHECK(T.relation("Noa") == string("mother"));
    CHECK(T.relation("Ziv") == string("grandfather"));
    CHECK(T.relation("Ron") == string("grandfather"));
    CHECK(T.relation("Yael") == string("grandmother"));
    CHECK(T.relation("Maly") == string("grandmother"));
    CHECK((T.relation("Gil") == string("great-grandfather") || 
            T.relation("Gil") == string("great-great-grandfather")));
    CHECK(T.relation("Gali") == string("great-great-grandmother"));
    CHECK(T.relation("Shalom") == string("great-grandfather"));
    CHECK(T.relation("Shir") == string("great-grandmother"));
    CHECK(T.relation("Shani") == string("great-great-grandmother"));
    CHECK(T.relation("Shin") == string("unrelated"));
    CHECK(T.relation("Rom") == string("unrelated"));
    CHECK(T.relation("Yonit") == string("unrelated"));
    CHECK_THROWS(T.relation("")); //invalid

}//15

TEST_CASE("test remove function") {
    CHECK_NOTHROW(T.remove("Yoni")); // remove father from the tree
    CHECK(T.relation("X") == string("me"));
    CHECK(T.relation("Noa") == string("mother"));
    CHECK(T.relation("Shani") == string("great-great-grandmother"));
    CHECK(T.relation("Yoni") == string("unrelated"));
    CHECK(T.relation("Ziv") == string("unrelated"));
    CHECK(T.relation("Yael") == string("unrelated"));
    CHECK(T.relation("Gil") == string("unrelated"));
    CHECK(T.relation("Gali") == string("unrelated"));
    CHECK(T.find("mother") == string("Noa"));
    CHECK(T.find("great-grandfather") == string("Shalom"));
    CHECK(T.find("great-grandmother") == string("Shir"));
    CHECK(T.find("great-great-grandmother") == string("Shani"));
    CHECK(T.find("great-great-great-grandmother") == string("Shoham"));
    CHECK_THROWS(T.find("great-great-grandfather")); //not exist after the remove
    CHECK_THROWS(T.find("father"));
    Tree T2("Y");
    CHECK_THROWS(T2.remove("Y")); // invalid to delete the root
    CHECK_NOTHROW(T2.addFather("Y","Eyal"));
    CHECK_NOTHROW(T2.addFather("Eyal", "Goten"));
    CHECK(T2.relation("Goten") == string("grandfather"));
    CHECK_NOTHROW(T2.addMother("Eyal", "Burma"));
    CHECK_THROWS(T2.remove("Goku")); //not exist in the tree
    CHECK_NOTHROW(T2.remove("Goten"));
    CHECK(T2.relation("Goten") == string("unrelated"));
    CHECK(T2.relation("Eyal") == string("father"));
}//26



