#ifndef _FAMILYTREE_H_
#define _FAMILYTREE_H_
#include<string>
using namespace std;

class node{

public:
    string name;
    node *father;
    node *mother;
    node(string name){
        this->name=name;
        this->father=NULL;
        this->mother=NULL;
    }
    // string getName(){
    //     return this->name;
    // }
};


namespace family{
class Tree{
    node *root;
    public:
    Tree(string name){
        node n(name);
        this->root = &n;
    }

    Tree& addFather(string child, string father);
    Tree& addMother(string child,string mother);
    string relation(string name);
    string find(string relation);
    void display();
    void display2(node *root , int space);
    bool remove(string name);
    node* findChild(node *root ,string child);
    node* getroot(){
        return this->root;
    }
};
}

#endif