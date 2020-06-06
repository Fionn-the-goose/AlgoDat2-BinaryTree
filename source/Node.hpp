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
void addNode(Node* root, int data);
// root = pointer to adress of root
Node* root;

#endif