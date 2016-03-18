/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	int i;
	struct node *head=NULL,*temp=NULL;
	if (N < 0)
		N = 0-N;
	if (N == 0)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->num = 0;
		head->next = NULL;
		return head;
	}
	else{
		while (N > 0)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			if (head == NULL)
			{
				temp->num = N % 10;
				head = temp;
				head->next = NULL;
				N = N / 10;
			}
			else{
				temp->num = N % 10;
				temp->next = head;
				head = temp;
				N = N / 10;
			}
		}
		return head;
	}
}