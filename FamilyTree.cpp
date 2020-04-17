#include "FamilyTree.hpp"
#include <iostream>
#include<string>
using namespace std;

namespace family{
    
    Tree::node::node(string name, string type){
        this->name=name;
        this->type = type;
        this->father=NULL;
        this->mother=NULL;
    }

    Tree::Tree(string name){
        this->root = new node(name, "me");
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
        else if(c->father != NULL){
            throw runtime_error("there is a father already!");
        }
        else{
            if(c->type == "me"){
                c->father = new node(father, "father");
            }
            else if(c->type == "mother" || c->type == "father"){
                c->father = new node(father, "grandfather");
            }
            else{
                string s = "great-" + c->type;
                int len = s.length();
                if(s.at(len-6) == 'm'){
                    s.replace(s.find("grandmother") , s.length() , "grandfather");
                }
                c->father = new node(father, s);
            }
        }
        cout << c->name << " " + c->type << endl;
        return *this;  
    }

    Tree& Tree::addMother(string child,string mother){
        node *c = search(this->root , child);
        if(c == NULL){
            throw runtime_error("this child does not exist!");
        }
        else if(c->mother != NULL){
            throw runtime_error("there is a mother already!");
        }
        else{
            if(c->type == "me"){
                c->mother = new node(mother, "mother");
            }
            else if(c->type == "mother" || c->type == "father"){
                c->mother = new node(mother, "grandmother");
            }
            else{
                
                string s = "great-" + c->type;
                int len = s.length();
                if(s.at(len-6) == 'f'){
                    s.replace(s.find("grandfather"), s.length() , "grandmother");
                }
            }
        }
        cout << c->name << " " + c->type << endl;
        return *this;
    }

    string Tree::relation(string name){
        node *n = search(this->root, name);
        if(n == NULL){
            return "unrelated";
        }
        return n->type;
    }

    string Tree::find(string relation){
        node *n = searchRelation(this->root ,relation);
        if (n == NULL){
            throw runtime_error("This relation does not exist in the tree");
        }
        return n->name;
    }

    void Tree::display(){
        printTree(this->root , 0);
    }

    void Tree::printTree(node *root , int space){
        // Base case  
        if (root == NULL)  
            return;  
  
        // Increase distance between levels  
        space += 10;  
  
        // Process right child first  
        printTree(root->father, space);  
  
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 10; i < space; i++)  
            cout<<" ";  
            cout<<root->name<<"\n";  
  
        // Process left child  
        printTree(root->mother, space);
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

    Tree::node* Tree::search(node *root ,string child){
        if (root == NULL){
            return NULL;
        }
        else if(child == root->name){
            return root;
        }

        node *m = search(root->mother, child);
        node *f = search(root->father,child);
    
        if (f != NULL){
            return f;
        }
        if(m != NULL){
            return m;
        }
        return NULL;
    }  

    Tree::node* Tree::searchRelation(node *root ,string relation){
        if (root == NULL){
            return NULL;
        }
        else if(root->type == relation){
            return root;
        }
        node *m = searchRelation(root->mother, relation);
        node *f = searchRelation(root->father,relation);

        if (f != NULL){
            return f;
        }
        if(m != NULL){
            return m;
        }
        return NULL;
    }   
}