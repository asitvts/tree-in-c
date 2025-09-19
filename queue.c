#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"


void init(Q** q, int cap){
	
	(*q)->capacity = cap;
	(*q)->arr = (Node**)calloc(cap, sizeof(Node*));
	(*q)->front=-1;
	(*q)->back=-1;

}

int getqsize(Q** q){
	
	if((*q)->back==-1)return 0;
	return ((*q)->back - (*q)->front)+1;
}

void push(Q** q, Node* node){

	if((*q)->back == (*q)->capacity-1){
		printf("queue is already full can't push\n");
		return;
	}	
	
	(*q)->back++;
	(*q)->arr[(*q)->back]=node;
	
	if((*q)->back==0)(*q)->front=0;
	
}

Node* front_ele(Q** q){
	
	if((*q)->front==-1){
		printf("queue empty\n");
		return NULL;
	}
	
	Node* curr = (*q)->arr[(*q)->front];
	
	return curr;
}


void pop(Q** q){

	if((*q)->front==-1){
		printf("queue empty\n");
		return ;
	}
	
	(*q)->arr[(*q)->front]=NULL;
	
	(*q)->front++;
	if((*q)->front > (*q)->back){
		(*q)->front=-1;
		(*q)->back=-1;
	}
	

}















