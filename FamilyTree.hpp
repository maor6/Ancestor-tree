#ifndef _FAMILYTREE_H_
#define _FAMILYTREE_H_
#include<string>
using namespace std;

namespace family{
    class Tree{
    
    class node{
        public:
        string name;
        node *father;
        node *mother;
        node(string name);
    };

    private:
    void display2(node *root , int space);
    node* search(node *root ,string child);

    public:
    node *root;
    Tree(string name);
    ~Tree();
    void del(node *n);
    Tree& addFather(string child, string father);
    Tree& addMother(string child,string mother);
    string relation(string name);
    string find(string relation);
    node* findChild(node *root ,string child);
    void display();
    bool remove(string name);
    
    


};
}

#endif