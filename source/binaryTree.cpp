#include "Node.hpp"
#include <iostream>
Node* root{nullptr};

//checks if binary tree is empty
bool isEmpty(){
    //if root pointer is nullpointer
    if(root!=nullptr){
        //tree is not empty
        return false;
    }
}
//function to create a new node
 Node* createNode(int data){
     //create temporary Node
    Node* temp = new Node();
    //temp Nodes data is parameter given data
    temp->data = data;
    // temp Nodes left and right pointer is nullpointer
    temp->right = temp->left = nullptr;
    return temp;
 }

//function to insert node
void addNode(Node* root, int data){
    int n{data};
    //if tree is empty
    if(root==nullptr){
        //root is new Node with data storaged
        root{createNode(data)};
    }
    else if(root->data>=data){
        addNode(root->left,data);
    }
    else addNode(root->right,data);
}

//function to search for data in tree
void search(Node* root, int data){
}

int main()
{
  std::cout << "Hello, World!\n";
  return 0;
}