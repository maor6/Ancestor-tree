#ifndef _FAMILYTREE_H_
#define _FAMILYTREE_H_
#include<string>
using namespace std;

namespace family{
    class Tree{
    
    class node{
        public:
        string name;
        string type;
        node *father;
        node *mother;
        node(string name, string type);
    };

    public:
    node *root;
    Tree(string name);
    void del(node *n);
    Tree& addFather(string child, string father);
    Tree& addMother(string child,string mother);
    string relation(string name);
    string find(string relation);
    void display();
    bool remove(string name);
    
    private:
    void printTree(node *root , int space);
    node* search(node *root ,string child);
    node* searchRelation(node *root ,string relation);



};
}

#endif