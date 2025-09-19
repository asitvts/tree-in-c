#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"


int main(){

	Node* root = build(NULL);
	
	bfs(root);


	return 0;
}
