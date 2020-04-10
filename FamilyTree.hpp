#ifndef _FAMILYTREE_H_
#define _FAMILYTREE_H_
#include<string>
using namespace std;

class node{
private:
    string name;
    node *father;
    node *mother;
public:
    node(string name){
        this->name=name;
        this->father=NULL;
        this->mother=NULL;
    }
    string getName(){
        return this->name;
    }
};


namespace family{
class Tree{
    node *root;
    public:

    Tree(string name){
        this->root = new node(name);
    }
    Tree& addFather(string child, string father);
    Tree& addMother(string child,string mother);
    string relation(string name);
    string find(string relation);
    void display();
    bool remove(string name);
};
}

#endif