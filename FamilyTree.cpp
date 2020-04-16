#include "FamilyTree.hpp"
#include <iostream>
#include<string>


namespace family{

Tree& Tree::addFather(string child, string father){
    node *c = findChild(this->root , child);
    if(c == NULL){
        throw runtime_error("this child does not exist!");
    }
    else if(c->father == NULL){
        node f(father);
        c->father = &f;
    }
    else{
        throw runtime_error("there is a father already!");
    }
    return *this;
}

Tree& Tree::addMother(string child,string mother){
    node *c = findChild(this->root , child);
    if(c == NULL){
        throw runtime_error("this child does not exist!");
    }
    else if(c->mother == NULL){
        node m(mother);
        c->mother = &m;
    }
    else{
        throw runtime_error("there is a mother already!");
    }
    return *this;
}

string Tree::relation(string name){
    return "";
}

string Tree::find(string relation){
    return "";
}

void Tree::display(){
    display2(this->root , 0);
}

void Tree::display2(node *root , int space){
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += 10;  
  
    // Process right child first  
    display2(root->father, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = 10; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
  
    // Process left child  
    display2(root->mother, space);
}

bool Tree::remove(string name){
    return true;
}


node* Tree::findChild(node *root ,string child){
    if(root == NULL){
        return root;
    }
    else if(child == root->name){
        return root;
    }
    else{
        findChild(root->father, child);
        findChild(root->mother, child);
    }
    return root;
}

}

