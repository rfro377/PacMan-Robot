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
	int x,y,f,g,h,px,py;
	struct node * next;
}node;
	
typedef struct linkedlist{
	node * head;
}linkedlist;
	
void createlinkedlist(linkedlist * ll, node data);


void addfirst( linkedlist * ll , node data);

void addat(linkedlist * ll, node data , int index);

void addlast(linkedlist * ll,node data );

node* getfirst(linkedlist * ll);

node* getat(linkedlist * ll, int index);

node* getlast(linkedlist * ll);

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
