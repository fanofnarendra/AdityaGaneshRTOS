#include <stdio.h>
#include<stdlib.h>
#include "FreeRTOS.h"
#include "task.h"

/* structure for a LinkedlistNode */
struct LinkedlistNode
{
	TaskHandle_t *taskHandl;
	long int deadline;
    struct LinkedlistNode *next;
};

/* Function to insert a LinkedlistNode at the beginning of a linked list */
void insertAtTheBegin(struct LinkedlistNode**, TaskHandle_t*, long int);

/* Function to bubble sort the given linked list */
void bubbleSort(struct LinkedlistNode*);

/* Function to swap data of two LinkedlistNodes a and b*/
void swap(struct LinkedlistNode*, struct LinkedlistNode*);

/* Function to print LinkedlistNodes in a given linked list */
void printList(struct LinkedlistNode*);
