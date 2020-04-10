#ifndef _FAMILYTREE_H_
#define _FAMILYTREE_H_
#include<string>
using namespace std;


namespace family{
class Tree{
    
    public:
        string name;
        Tree *father;
        Tree *mother;
    
    Tree(string name);
    bool addFather(string child, string father);
    bool addMother(string child,string mother);
    string relation(string name);
    string find(string relation);
    void display();
    bool remove(string name);
};

#endif