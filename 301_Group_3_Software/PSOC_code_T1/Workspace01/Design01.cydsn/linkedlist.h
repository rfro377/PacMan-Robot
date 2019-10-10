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
#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct data {
	int x,y,f,g,h,px,py;
}data;
    
typedef struct node {
    data data; 
	struct node * next;
}node;
	
typedef struct linkedlist{
	node * head;
}linkedlist;
	
void createlinkedlist(linkedlist * ll, data data);

void addfirst( linkedlist * ll , data data);

void addat(linkedlist * ll, data data , int index);

void addlast(linkedlist * ll, data data );

data getfirst(linkedlist * ll);

data getat(linkedlist * ll, int index);

data getlast(linkedlist * ll);

void removefirst(linkedlist * ll);

void removelast(linkedlist * ll);

void printlist(linkedlist * ll);

/*

Helper functions!

*/

node * nodeat(node * current, int index);

node * nodesecondlast(node * current);

node * nodelast(node * current);

void setdata(data* data, int x, int y, int f, int g, int h, int px, int py);

void copydata(data * left, data right);

data createdata(int x, int y, int f, int g, int h, int px, int py);
/* [] END OF FILE */
#endif /* _MY_HEADER_H_ */
