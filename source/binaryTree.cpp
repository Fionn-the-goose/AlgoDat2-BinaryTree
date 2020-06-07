#include "Node.hpp"
#include <iostream>

Node* root{nullptr};

// Find successor and predecessor
void successorPredecessor(Node* root, int data) {
	if (root != nullptr){
		if (root->data = data) {
		//most right element in the left subtree is predecessor
			if (root->left != nullptr) {
				Node* tmp = root->left;
				while (tmp->right != nullptr) {
						tmp = tmp->right;
				}
				int predecessor = tmp->data;
			}
			if (root->right != nullptr) {
			//most left element in right subtree is successor
				Node* tmp = root->right;
				while(tmp->left != nullptr) {
					tmp = tmp->left;
				}
				int successor = tmp->data;
			}
			else if (root->data > data) {
				//root is turned successor if data matches with the root
				int successor = root->data;
				successorPredecessor(root->left, data);
			} 
            else if (root->data < data) {
				//root is predecessor if data matches with root
				int predecessor = root->data;
				successorPredecessor(root->right, data);
			}
		}
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


// Returns maximum value
int maxValue(Node* node){    
    //find leaf thats rightmost 
    Node* tmp = node; 
    while (tmp->right != NULL)  
        tmp = tmp->right; 
      
    return (tmp->data); 
}  

// Returns minimum value
int minValue(Node* node){    
    //find leaf thats leftmost 
    Node* tmp = node; 
    while (tmp->left != NULL)  
        tmp = tmp->left; 
      
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
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* tmp = createNode(minValue(root->right)); 
        // Copy the inorder successor's content to this node 
        root->data = tmp->data; 
        // Delete the inorder successor 
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
//function to print BST
void printTree(){

}

int main(){

}