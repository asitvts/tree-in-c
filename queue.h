#ifndef QUEUE_H
#define QUEUE_H



#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


typedef struct Q{
	
	Node** arr;
	int capacity;
	int front;
	int back;

}Q;

void init(Q* q, int cap);


int getqsize(Q* q);

void push(Q* q, Node* node);

Node* front_ele(Q* q);


void pop(Q* q);



#endif 
