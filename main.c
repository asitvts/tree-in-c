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
	
	leftView(root);
	
	nl
	
	rightView(root);
	
	
	nl
	
	top_view(root);
	
	nl
	
	bot_view(root);
	
	nl
	
	target_pathsum(root,3);
	target_pathsum(root,4);
	target_pathsum(root,1);
	
	nl


	morrisTraversal2(root);
	
	nl
	
	
	morrisTraversalPreorder(root);
	
	nl
	
	boundary(root);
	
	nl
	
	return 0;
}



