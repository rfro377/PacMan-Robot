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
#include <linkedlist.h>
#define INVALID 4294967295
	
void createlinkedlist(linkedlist * ll, node* data){
        ll->head = NULL;
		ll->head = malloc(sizeof(node));
		if (ll->head == NULL){
			return;
		}
		ll->head = data;
		ll->head->next = NULL;
}

void addfirst(linkedlist * ll , node* data){
	node *newn;
	newn = malloc(sizeof(node));
	if (newn == NULL){
		return;
	}
	newn = data;
	newn->next = ll->head;
	ll->head = newn;
}

void addat(linkedlist * ll, node* data , int index){
	if(index == 0){
		addfirst(ll,data);
		return;
	}
	node * previous = nodeat(ll->head, index-1);
	if(previous == INVALID){
		return;
	}
	node *newn = malloc(sizeof(node));
	newn->next = previous->next;
	newn =data;
	previous->next=newn;
}

void addlast(linkedlist * ll,node* data){
	node * last = nodelast(ll->head);
	last->next = malloc(sizeof(node));
	last->next = data;
	last->next->next = NULL;
}

node* getfirst(linkedlist * ll){
	return ll->head;
}

node* getat(linkedlist * ll, int index){
	node * current = nodeat(ll->head, index);
	return current;
}

node* getlast(linkedlist * ll){
	node *last = nodelast(ll->head);
	return last;
}

void removefirst(linkedlist * ll){
	node *second = ll->head->next;
	if (second == NULL){
		return;
	}
	free(ll->head);
	ll->head = second;
}

void removelast(linkedlist * ll){
	if (ll->head->next == NULL){
        return;
	}
	node * secondlast = nodesecondlast(ll->head);
	free(secondlast->next);
	secondlast->next = NULL;
}


/*

Helper functions!

*/

node * nodeat(node * current, int index){
    int i = 0;
	while(i < index){
		current = current->next;
		if (current->next == NULL && i != index-1){
            node * invalid;
            invalid = INVALID;
			return invalid;
		}
        i++;
	}
	return current;
}

node * nodesecondlast(node * current){
	while(current->next->next != NULL){
		current = current->next;
	}
	return current;
}

node * nodelast(node * current){
	while(current->next != NULL){
		current = current->next;
	}
	return current;
}


/*
    Test Methods
*/

void printlist(linkedlist * ll){
	node *current = ll->head;
	while(current->next != NULL){
		printf(current);
		printf("/n");
		current = current->next;
	}
	printf(current);
}

/*

Test Code

*/
/* [] END OF FILE */
