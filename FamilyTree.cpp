#include "FamilyTree.hpp"
#include <iostream>
//#include<string>


namespace family{
    
    Tree::node::node(string name){
        this->name=name;
        this->father=NULL;
        this->mother=NULL;
    }

    Tree::Tree(string name){
        this->root = new node(name);
    }

    Tree::~Tree(){
        del(this->root);
        cout << "the Tree is deleted" << endl; 
    }

    void Tree::del(node *n){
        if(n == NULL){
            return;
        } 
        del(n->father);
        del(n->mother);
        delete n;
    }

    Tree& Tree::addFather(string child, string father){
        node *c = Tree::search(this->root , child);
        if(c == NULL){
            throw runtime_error("this child does not exist!");
        }
        else if(c->father == NULL){
            c->father = new node(father);
        }
        else{
            throw runtime_error("there is a father already!");
        }
        return *this;  
    }

    Tree& Tree::addMother(string child,string mother){
        node *c = search(this->root , child);
        if(c == NULL){
            throw runtime_error("this child does not exist!");
        }
        else if(c->mother == NULL){
            c->mother = new node(mother);
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
        if(name == this->root->name){
            throw runtime_error("cant delete the root");
        }
        node *c =  search(this->root,name);
        if(c == NULL){
            return false;
        }
        del(c);
        return true;
    }

    Tree::node* Tree::findChild(node *root ,string child){
         cout << root->name << endl;
        if(root == NULL){
            return NULL;
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

    Tree::node* Tree::search(node *root ,string child){
        if(root == NULL){
            return NULL;
        }
        if(child == root->name){
            return root;
        }
        if(root->father != NULL){
            return search(root->father, child);
        }
        if(root->mother != NULL){
            return search(root->mother, child);
        }
        return root;
    }   
}