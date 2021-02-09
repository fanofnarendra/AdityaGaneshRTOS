#include <linkedlist.h>

/* Function to insert a LinkedlistNode at the beginning of a linked list */
void insertAtTheBegin(struct LinkedlistNode **head_ref, TaskHandle_t *taskHandl, long int *deadline)
{
    struct LinkedlistNode *ptr1 = (struct LinkedlistNode*)malloc(sizeof(struct LinkedlistNode));
    ptr1->taskHandl = taskHandl;
    ptr1->deadline = deadline;
    ptr1->next = *head_ref;
    *head_ref = ptr1;
}

/* Function to print LinkedlistNodes in a given linked list */
void printList(struct LinkedlistNode *head)
{
    struct LinkedlistNode *temp = head;
    printf("\n");
    while (temp!=NULL)
    {
        printf("%lu\t", *(temp->deadline));
        temp = temp->next;
    }
    printf("\n");
}

/* Bubble sort the given linked list */
void bubbleSortLinkedList(struct LinkedlistNode *head)
{
    int swapped, i;
    struct LinkedlistNode *ptr1;
    struct LinkedlistNode *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (*(ptr1->deadline) > *(ptr1->next->deadline))
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap task handler and deadline of two LinkedlistNodes a and b*/
void swap(struct LinkedlistNode *a, struct LinkedlistNode *b)
{
    TaskHandle_t* tempTaskHandl = a->taskHandl;
    long int *tempDeadline = a->deadline;
    a->taskHandl = b->taskHandl;
    a->deadline = b->deadline;
    b->taskHandl = tempTaskHandl;
    b->deadline = tempDeadline;
}

/* Function to find GCD of numbers*/
long int gcdLinkedList(struct LinkedlistNode* head)
{
	long int gcd = 1;
	struct LinkedlistNode* ptr = NULL;
	if(head != NULL)
	{
		gcd = *(head->deadline);
		if(head->next != NULL)
		{
			ptr = head->next;
			while(ptr != NULL)
			{
				gcd = gcdTwo(gcd, *(ptr->deadline));
				ptr = ptr->next;
			}
		}
	}

	return gcd;
}
