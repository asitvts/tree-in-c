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

	return 0;
}
