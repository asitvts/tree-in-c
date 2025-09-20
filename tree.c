#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"



int max(int a, int b){
	
	if(a>=b)return a;
	return b;

}


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
			
				
			if(node->left)push(q, node->left);
			if(node->right)push(q, node->right);
			
		}
	
	}
	free(q->arr);
	q->arr=NULL;
	free(q);
	q=NULL;
	
	return root;
	
}



void bfs(Node* root){

	if(!root)return;

	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	push(q,root);
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			
			printf("%d ", node->val);
			
				
			if(node->left)push(q, node->left);
			if(node->right)push(q, node->right);
	
			
		}
		
		printf("\n");
	
	}
	
	free(q->arr);
	q->arr=NULL;
	free(q);
	q=NULL;

}

void inorder(Node* root){
	
	if(!root){
		return;
	}
	
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void preorder(Node* root){
	
	if(!root){
		return;
	}
	
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}



void postorder(Node* root){
	
	if(!root){
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}


int height(Node* root){
	if(!root)return 0;
	
	return max(height(root->left), height(root->right))+1;

}


int diameter(Node* root){

	if(!root)return 0;
	
	int right_height = height(root->right);
	int left_height = height(root->left);
	
	return max((right_height+left_height+1) , max(diameter(root->left), diameter(root->right) ) );
}


void leftView(Node* root){
	printf("printing the left view of the tree\n");
	
	if(!root)return;

	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	push(q,root);
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		int left_val = -1;
		int first_iter=1;
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			if(first_iter){
				first_iter=0;
				left_val=node->val;
			}
			
			
				
			if(node->left)push(q, node->left);
			if(node->right)push(q, node->right);
			
		}
		
		printf("%d ", left_val);
	
	}
	
	free(q->arr);
	q->arr=NULL;
	free(q);
	q=NULL;
	
}



void rightView(Node* root){
	printf("printing the right view of the tree\n");
	
	if(!root)return;

	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	push(q,root);
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		int right_val = -1;
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			
			right_val=node->val;
			
				
			if(node->left)push(q, node->left);
			if(node->right)push(q, node->right);
			
		}
		
		printf("%d ", right_val);
	
	}
	
	free(q->arr);
	q->arr=NULL;
	free(q);
	q=NULL;
	
}

void morrisTraversal(Node* root){

	printf("printing the morris traversal of tree\n");

	while(root){
	
		if(!root->left){
			printf("%d ", root->val);
			root=root->right;
		}
		else if(root->left){
		
			Node* temp=root->left;
			while(temp->right)temp=temp->right;
			temp->right=root;
			
			
			Node* to_set_null=root;
			root=root->left;			// move to left from root
			
			to_set_null->left=NULL;		// set the linkage from root to its left to NULL to avoid repition while travelling
			
		
		}
		
	}
	
}








