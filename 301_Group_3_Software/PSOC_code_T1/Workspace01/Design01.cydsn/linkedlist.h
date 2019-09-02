/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
}node;
	
typedef struct linkedlist{
	node * head;
}linkedlist;
	
void createlinkedlist(linkedlist * ll, int data);


void addfirst( linkedlist * ll , int data);

void addat(linkedlist * ll, int data , int index);

void addlast(linkedlist * ll,int data );

int getfirst(linkedlist * ll);

int getat(linkedlist * ll, int index);

int getlast(linkedlist * ll);

void removefirst(linkedlist * ll);

void removelast(linkedlist * ll);

void printlist(linkedlist * ll);

/*

Helper functions!

*/

node * nodeat(node * current, int index);

node * nodesecondlast(node * current);

node * nodelast(node * current);
/* [] END OF FILE */
