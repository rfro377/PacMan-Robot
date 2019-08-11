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
	
void createlinkedlist(linkedlist * ll, int data){
        ll->head = NULL;
		ll->head = malloc(sizeof(node));
		if (ll->head == NULL){
			return;
		}
		ll->head->data = data;
		ll->head->next = NULL;
}

void addfirst(linkedlist * ll , int data){
	node *newn;
	newn = malloc(sizeof(node));
	if (newn == NULL){
		return;
	}
	newn->data = data;
	newn->next = ll->head;
	ll->head = newn;
}

void addat(linkedlist * ll, int data , int index){
	if(index == 0){
		addfirst(ll,data);
		return;
	}
	node * previous = nodeat(ll->head, index-1);
	if(previous->data == NULL){
		return;
	}
	node *newn = malloc(sizeof(node));
	newn->next = previous->next;
	newn->data=data;
	previous->data=newn->data;
}

void addlast(linkedlist * ll,int data){
	node * last = nodelast(ll->head);
	last->next = malloc(sizeof(node));
	last->next->data = data;
	last->next->next = NULL;
}

int getfirst(linkedlist * ll){
	return ll->head->data;
}

int getat(linkedlist * ll, int index){
	node * current = nodeat(ll->head, index);
	return current->data;
}

int getlast(linkedlist * ll){
	node *last = nodelast(ll->head);
	return last->data;
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
	node * secondlast = nodesecondlast(ll->head);
    if(secondlast->data == NULL){
		return;
	}
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
		if (current->next == NULL && i < index){
            node * invalid;
            invalid->data = NULL;
			return invalid;
		}
        i++;
	}
	return current;
}

node * nodesecondlast(node * current){
	if (current->next == NULL){
        node * invalid;
        invalid->data = NULL;
        return invalid;
	}
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
		printf(current->data);
		printf("/n");
		current = current->next;
	}
	printf(current->data);
}

/*

Test Code

*/
/* [] END OF FILE */
