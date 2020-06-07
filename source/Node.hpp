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
Node* createNode(int data);
Node* addNode(Node* root, int value);
int maxValue(Node* node);
int minValue(Node* node);
Node* deleteNode(Node* root, int data);
Node* search(Node* root, int data);
void successorPredecessor(Node* root, Node*& pre, Node*& succ, int data);
void printSuccPre(Node* root, int data);
void printTree(Node* root);

// root = pointer to adress of root
Node* root;

#endif