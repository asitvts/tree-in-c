#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"


void init(Q* q, int cap){
	
	q->capacity = cap;
	q->arr = (Node**)calloc(cap, sizeof(Node*));
	q->front=-1;
	q->back=-1;

}

int getqsize(Q* q){
	
	if(q->back==-1)return 0;
	
	if(q->back >= q->front)return (q->back - q->front)+1;
	else return (q->back+1)+(q->capacity-q->front);
}

void push(Q* q, Node* node){
	
	if(q->back==-1 && q->front==-1){
		q->back=0;
		q->front=0;
		q->arr[q->back]=node;
		return;
	}
	int next_ind=(q->back+1)%q->capacity;
	if(q->front==next_ind){
		printf("cannot push more, queue already full\n");
		return;
	}
	q->back=next_ind;
	q->arr[q->back]=node;
	
	return;
}

Node* front_ele(Q* q){
	
	if(q->front==-1){
		printf("queue empty\n");
		return NULL;
	}
	
	Node* curr = q->arr[q->front];
	
	return curr;
}


void pop(Q* q){

	if(q->front==-1){
		printf("queue empty\n");
		return ;
	}
	
	q->arr[q->front]=NULL;
	
	if(q->front == q->back){
		q->front=-1;
		q->back=-1;
		return;
	}
	
	q->front = (q->front+1)%q->capacity;
	
}















