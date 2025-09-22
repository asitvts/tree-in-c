#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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






void morrisTraversal2(Node* current){

	printf("printing the morris traversal of tree without breaking the structure of tree\n");
	
	
	Node* root=current;
	Node* pre;
	
	while(root){
	
		if(!root->left){
			printf("%d ", root->val);
			root=root->right;
		}
		else{
					
			pre=root->left;
			while(pre->right && pre->right!=root)pre=pre->right;
			
			
			if(!pre->right){
				pre->right=root;
				root=root->left;
			}
			
			else{
				pre->right=NULL;
				printf("%d ", root->val);
				root=root->right;
			}
			

		}
		
	}
	
}




void morrisTraversalPreorder(Node* current){

	printf("printing the morris(Preorder) traversal of tree without breaking the structure of tree\n");
	
	
	Node* root=current;
	Node* pre;
	
	while(root){
	
		if(!root->left){
			printf("%d ", root->val);
			root=root->right;
		}
		else{
					
			pre=root->left;
			while(pre->right && pre->right!=root)pre=pre->right;
			
			
			if(!pre->right){
				pre->right=root;
				printf("%d ", root->val);
				root=root->left;
			}
			
			else{
				pre->right=NULL;
				root=root->right;
			}
			

		}
		
	}
	
}


void top_view(Node* root){
	
	printf("printing the top view of the tree\n");
	
	if(!root)return;
	
	int seen[1000];
	memset(seen,-1,sizeof(seen));

	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	root->hd=500;
	int min_hd=500,max_hd=500;
	
	push(q,root);
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			int ind = node->hd;
			if(seen[ind]==-1){
				seen[ind]=node->val;
			}
				
			if(node->left){
				node->left->hd=ind-1;
				if(ind-1<min_hd)min_hd=ind-1;
				push(q, node->left);
			}
			
			if(node->right){
				node->right->hd=ind+1;
				if(ind+1>max_hd)max_hd=ind+1;
				push(q, node->right);
			}
			
		}
	
	}
	
	free(q->arr);
	q->arr=NULL;
	free(q);
	q=NULL;
	
	for(int i=min_hd; i<=max_hd; i++){
		if(seen[i]!=-1){
			printf("%d ",seen[i]);
		}
	}

}




void bot_view(Node* root){
	
	printf("printing the bottom view of the tree\n");
	
	if(!root)return;
	
	int seen[1000];
	memset(seen,-1,sizeof(seen));

	Q* q = calloc(1, sizeof(Q));
	
	init(q,1000);
	
	root->hd=500;
	int min_hd=500,max_hd=500;
	
	push(q,root);
	
	while(getqsize(q)>0){
	
		int size = getqsize(q);
		
		
		while(size--){
		
			Node* node = front_ele(q);
			pop(q);
			
			int ind = node->hd;
			seen[ind]=node->val;
			
				
			if(node->left){
				node->left->hd=ind-1;
				if(ind-1<min_hd)min_hd=ind-1;
				push(q, node->left);
			}
			
			if(node->right){
				node->right->hd=ind+1;
				if(ind+1>max_hd)max_hd=ind+1;
				push(q, node->right);
			}
			
		}
	
	}
	
	free(q->arr);
	q->arr=NULL;
	free(q);
	q=NULL;
	
	for(int i=min_hd; i<=max_hd; i++){
		if(seen[i]!=-1){
			printf("%d ",seen[i]);
		}
	}

}




int find(Node* root, const int target, int curr_sum) {
    if (!root) return 0; 

    curr_sum += root->val;

    // Check if this is a leaf node
    if (!root->left && !root->right) {
        return curr_sum == target;
    }

    // Recurse on children
    return find(root->left, target, curr_sum) || find(root->right, target, curr_sum);
}


void target_pathsum(Node* root, const int t){

	if(find(root,t,0)){
		printf("that target pathsum exists\n");
	}
	else{
		printf("no such target path sum available\n");
	}

}



int isLeaf(Node* node){
	return !node->left && !node->right;
}

void left(Node* root, int* ind, int arr[100]){
	if (!root || isLeaf(root)) return;

	arr[*ind] = root->val;
	(*ind)++;

	if (root->left) left(root->left, ind, arr);
	else left(root->right, ind, arr);
}

void leaf(Node* root, int* ind, int arr[100]){
	if (!root) return;

	if (isLeaf(root)) {
		arr[*ind] = root->val;
		(*ind)++;
	}

	leaf(root->left, ind, arr);
	leaf(root->right, ind, arr);
}

void right(Node* root, int* ind, int arr[100]){
	if (!root || isLeaf(root)) return;

	if (root->right) right(root->right, ind, arr);
	else right(root->left, ind, arr);

	arr[*ind] = root->val;
	(*ind)++;
}

void boundary(Node* root){
	if (!root) return;

	int arr[100];
	int ind = 0;

	if (!isLeaf(root)) {
		arr[ind++] = root->val;
	}

	left(root->left, &ind, arr);
	leaf(root, &ind, arr);


	int right_arr[100];
	int right_ind = 0;
	right(root->right, &right_ind, right_arr);

	
	for (int i = right_ind - 1; i >= 0; i--) {
		arr[ind++] = right_arr[i];
	}

	for (int i = 0; i < ind; i++) {
		printf("%d ", arr[i]);
	}

}












