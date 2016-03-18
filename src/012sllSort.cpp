/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int count0 = 0, count1 = 0,count2=0;
	struct node *first=head;
	while (first != NULL)
	{
		if (first->data == 0)
			count0++;
		else if (first->data == 1)
			count1++;
		else
			count2++;
		first = first->next;
	}
	//head = first;
	while (head!= NULL)
	{
		if (count0>0)
		{
			head->data = 0;
			count0--;
			head = head->next;
		}
		else if (count1>0 && count0 == 0)
		{
			head->data = 1;
			count1--;
			head = head->next;
		}
		else if (count2>0 && count1 == 0 && count0 == 0)
		{
			head->data = 2;
			head = head->next;
			count2--;
		}
	}
	
}