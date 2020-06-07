#include "Node.hpp"
#include <iostream>
#include <fstream>

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
 Node* addNode(Node* root, int value) {
     if (root == NULL) {
         root = createNode(value);
     }

     else if (value <= root->data) {
         root->left = addNode(root->left, value);
     }

     else {
         root->right = addNode(root->right, value);
     }
     return root;
 }


// Returns maximum value
int maxValue(Node* node){    
    //find leaf thats rightmost 
    Node* tmp = node; 
    while (tmp->right != NULL){
        tmp = tmp->right;     
    }   
    std::cout << "the maximum is: "<< tmp->data << std::endl;  
    return (tmp->data); 
}  

// Returns minimum value
int minValue(Node* node){    
    //find leaf thats leftmost 
    Node* tmp = node; 
    while (tmp->left != NULL){
        tmp = tmp->left;  
    }  
    std::cout <<"the minimum is: " << tmp->data << std::endl;
    return (tmp->data);  
}  

//function to delete data and return new root
Node* deleteNode(Node* root, int data){ 
    //case if root is nullpointer 
    if(root == nullptr){
        return root; 
    }
    //If data is smaller than the root data look left side of tree
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
    // If data is larger than the root data look right side of tree 
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
    // if data is same as root data, delete root
    else{ 
        // node with one child or no child 
        if (root->left == nullptr){ 
            Node* tmp = root->right; 
            free(root); 
            return tmp; 
        } 
        else if (root->right == nullptr){ 
            Node *tmp = root->left; 
            free(root); 
            return tmp; 
        } 
        // node with two children-> find the smallest in the right subtree
        Node* tmp = createNode(minValue(root->right)); 
        //copy smallest value to tmp 
        root->data = tmp->data; 
        //delete tmp
        root->right = deleteNode(root->right, tmp->data); 
    } 
    return root; 
} 

//function to search for data in tree
Node* search(Node* root, int data){ 
    // if root is null or data is present at root 
    if (root == nullptr || root->data == data) 
       return root; 
     
    //data is bigger than root data
    if (root->data < data) 
       return search(root->right, data); 
  
    //data is smaller than root data 
    return search(root->left, data); 
}

// Find successor and predecessor
void successorPredecessor(Node* root, Node*& pre, Node*& succ, int data){ 
    if(root == nullptr){
        return;
    }
    //find data in bst
    while (root != nullptr){ 
        //if root is data
        if(root->data == data) { 
            //minimum in right subtree is predecessor.
            if (root->right) { 
                succ = root->right; 
                while (succ->left) 
                    succ = succ->left; 
            } 
            //maximum value in left subtree is successor
            if(root->left) { 
                pre = root->left; 
                while (pre->right) 
                    pre = pre->right; 
            } 
            return; 
        } 
        //if data bigger than root -> data is in right subtree
        //if left subtree is nullptr root could be predecessor
        else if (root->data < data){ 
            pre = root; 
            root = root->right; 
        } 
        //if data is smaller than root -> data is in left subtree
        //if right subtree is nullptr is null root could be successor
        else { 
            succ = root; 
            root = root->left; 
        }  
    }
}

//print successor and predecessor
void printSuccPre(Node* root, int data){
    Node *pre{nullptr};
    Node *succ{nullptr};

    successorPredecessor(root, pre, succ, data);
    if(pre != nullptr){
    std::cout<<"predecessor is: "<<pre->data<<std::endl;
    }
    if(pre == nullptr){
    std::cout<<"null";
    }   
    if(succ != nullptr){
    std::cout<<"successor is: "<<succ->data<<std::endl;
    }
    if(succ == nullptr){
    std::cout<<"null"<<std::endl;
    }
}

//function to print BST
int counter = 0;
void printTree(Node* root){
    if (root == nullptr) {
        return;
    }
    else if (root->left != nullptr && root->right != nullptr) {
        std::cout << root->data << "->" << root->left->data << std::endl;
        std::cout << root->data << "->" << root->right->data << std::endl;
    }
    else if(root->left != nullptr && root->right == nullptr) {
        std::cout << root->data << "->" << root->left->data << std::endl;
        std::cout << root->data << "->" << "null" << counter << std::endl;
        counter++;
    }
    else if (root->left == nullptr && root->right != nullptr) {
        std::cout << root->data << "->" << "null" << counter << std::endl;
        std::cout << root->data << "->" << root->right->data << std::endl;
        counter++;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        std::cout << root->data << "->" << "null" << counter << std::endl;
        counter++;
        std::cout << root->data << "->" << "null" << counter << std::endl;
        counter++;
    }
    printTree(root->left);
    printTree(root->right);
}

int main(){
    Node* root = createNode(8);
    addNode(root, 3);
    addNode(root, 10);
    addNode(root, 1);
    addNode(root, 6);
    addNode(root, 4);
    addNode(root, 7);
    addNode(root, 14);
    addNode(root, 13);
    printTree(root);
    minValue(root);
    maxValue(root);
    printSuccPre(root, 7);
    std::cout<<"\n"<<std::endl;

    
    deleteNode(root, 10);
    printTree(root);
    minValue(root);
    maxValue(root);
    printSuccPre(root, 6);
    std::cout<<"\n"<<std::endl;

    deleteNode(root, 1);
    printTree(root);
    minValue(root);
    maxValue(root);
    printSuccPre(root, 14);
    std::cout<<"\n"<<std::endl; 

    //adress of node with data 6
    std::cout<<search(root, 6)<<std::endl;
    //adress of node with data 13
    std::cout<<search(root, 13)<<std::endl;
    //node that is not in the tree does not own a address
    std::cout<<search(root, 90)<<std::endl;
}