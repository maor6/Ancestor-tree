#include "FamilyTree.hpp"
#include <iostream>
#include<string>

namespace family{

Tree& Tree::addFather(string child, string father){
    return *this;
}

Tree& Tree::addMother(string child,string mother){
    return *this;
}

string Tree::relation(string name){
    return "";
}

string Tree::find(string relation){
    return "";
}

void Tree::display(){

}

bool Tree::remove(string name){
    return true;
}
}

