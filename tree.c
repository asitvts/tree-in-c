#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"


Node* build(Node* root){

	if(!root){
		root= calloc(1,sizeof(Node));
		
		int data;
		printf("give value of root node: ");
		scanf("%d",&data);
		
		if(data==-1)return NULL;
		
		root->val=data;
	}
	
	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	push(q,root);
	
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			
			if(!node)continue;
			
			int data;
			printf("give left child of %d node, -1 for NULL: ", node->val);
			scanf("%d", &data);
			if(data==-1)node->left=NULL;
			else{
				node->left = (Node*)calloc(1, sizeof(Node));
				node->left->val=data;
			}
			
			
			printf("give right child of %d node, -1 for NULL: ", node->val);
			scanf("%d", &data);
			if(data==-1)node->right=NULL;
			else{
				node->right = (Node*)calloc(1, sizeof(Node));
				node->right->val=data;
			}
			
				
			push(q, node->left);
			push(q, node->right);
			
		}
	
	}
	
	free(q);
	q=NULL;
	
	return root;
	
}



void bfs(Node* root){

	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	push(q,root);
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			
			if(node)printf("%d ", node->val);
			else printf("N ");
			
			if(node){
				
				push(q, node->left);
				push(q, node->right);
			
			}
			
		}
		
		printf("\n");
	
	}
	
	free(q);
	q=NULL;

}





