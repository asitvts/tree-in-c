#ifndef TREE_H
#define TREE_H



#include <stdio.h>
#include <stdlib.h>



typedef struct Node{

	int val;
	struct Node* left;
	struct Node* right;

}Node;



Node* build(Node* root);


void bfs(Node* root);

void inorder(Node* root);

void preorder(Node* root);

void postorder(Node* root);



#endif 
