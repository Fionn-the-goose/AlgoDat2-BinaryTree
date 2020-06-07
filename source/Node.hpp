#ifndef NODE_HPP
#define NODE_HPP

struct Node
{
    //data stored in child or parent
    int data;
    //pointer to the left node
    Node* left;
    //pointer to the right node
    Node* right;
};
void successorPredecessor(Node* root, int data);
Node* createNode(int data);
Node* addNode(Node* root, int value);
int maxValue(Node* node);
int minValue(Node* node);
Node* deleteNode(Node* root, int data);
Node* search(Node* root, int data);

// root = pointer to adress of root
Node* root;

#endif