#include <iostream>
#include "binarysearch.hpp"

Node* getnew(int value){
	Node* newNode {new Node()};
	newNode->storrage_ = value;
	newNode->left_ = NULL;
	newNode->right_ = NULL;
	return newNode;
}

Node* insert(Node* root, int value) {
	if (root == NULL) {
		root = getnew(value);
	}

	else if (value <= root->storrage_) {
		root->left_ = insert(root ->left_,value);
	}

	else if (value >= root->storrage_) {
		root->right_ = insert(root->right_, value);
	}
	else
	return root;
}