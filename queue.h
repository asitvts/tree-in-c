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

void init(Q** q, int cap);


int getqsize(Q** q);

void push(Q** q, Node* node);

Node* front_ele(Q** q);


void pop(Q** q);



#endif 








/*
why add the guards


Why are include guards necessary?

When you compile C code, the compiler literally copies and pastes the contents of header files wherever you write #include "header.h". This is called textual inclusion.

If the same header file is included multiple times in your project — say:

Directly in multiple .c files

Or indirectly because tree.h includes queue.h, and queue.h includes tree.h again —

then the compiler ends up seeing the same declarations and definitions multiple times.

For example:

// tree.h (without guards)

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;


If this is included twice, the compiler says:
"Hey, you've already defined struct Node!" — and you get errors.

What do include guards do?

They act as a conditional compilation flag that tells the compiler:
"If this header has already been included once, skip it the next time."

They look like:

#ifndef TREE_H    // If TREE_H is not defined
#define TREE_H    // Define TREE_H now

// Your header contents here

#endif // End of the conditional


The first time the header is included, TREE_H isn’t defined, so the compiler processes the file and defines TREE_H.
The second time it tries to include the same header, TREE_H is already defined, so the compiler skips the content inside the guards.

Why add guards only in .h files?

Headers are meant to be included multiple times:
Their job is to provide declarations, macros, typedefs, and function prototypes that multiple .c files can use.
Because they get included everywhere, they need protection against multiple inclusions.

Source (.c) files are compiled separately:
Each .c file is compiled on its own into an object file. You don’t #include .c files inside other .c files normally.
So no need for guards there.

Bonus: Alternative to include guards — #pragma once

Many modern compilers support this as a simpler alternative:

#pragma once

// header content


It achieves the same effect but is non-standard (though widely supported).

Tip: The macro name (HELLO_H) is usually:

The uppercase version of the filename

Non-conflicting and unique enough within your project


*/





