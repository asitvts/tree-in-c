#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

#define nl printf("\n\n");


int main(){

	Node* root = build(NULL);
	
	bfs(root);
	
	printf("inorder\n");
	inorder(root);
	nl
	printf("preorder\n");
	preorder(root);
	nl
	printf("postorder\n");
	postorder(root);
	nl
	
	printf("height of the tree is : %d\n", height(root));
	
	nl 
	
	printf("diameter of the tree is : %d", diameter(root));
	
	nl

	return 0;
}
