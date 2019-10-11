#include <stdlib.h>
#include <linkedlist.h>
	

void createlinkedlist(linkedlist * ll, data data){
    ll->head = NULL;
	ll->head = malloc(sizeof(node));
	if (ll->head == NULL){
		return;
	}
	copydata(&ll->head->data,data);
	ll->head->next = NULL;
    return;
}

void addfirst(linkedlist * ll, data data){
	node *newn;
	newn = malloc(sizeof(node));
	if (newn == NULL){
		return;
	}
	newn->data = data;
	copydata(&(newn->data),data);
	newn->next = ll->head;
	ll->head = newn;
    return;
}

void addat(linkedlist * ll, data data , int index){
	if(index == 0){
		addfirst(ll,data);
		return;
	}
	node * previous = nodeat(ll->head, index-1);
	if(&(previous->data) == NULL){
		return;
	}
	node* newn = malloc(sizeof(node));
	newn->next = previous->next;
	newn->data=data;
	copydata(&(newn->data),data);
	previous->next=newn;
    return;
}

void addlast(linkedlist * ll, data data){
	node *last = nodelast(ll->head);
	last->next = malloc(sizeof(node));
	last->next->data = data;
	copydata(&(last->next->data),data);
	last->next->next = NULL;
    return;
}

data getfirst(linkedlist * ll){
	return ll->head->data;
}

data getat(linkedlist * ll, int index){
	node* current = nodeat(ll->head, index);
	return current->data;
}

data getlast(linkedlist * ll){
	node* last = nodelast(ll->head);
	return last->data;
}

void removefirst(linkedlist * ll){
	node *second = ll->head->next;
	if (second == NULL){
		return;
	}
	free(ll->head);
	ll->head = second;
    return;
}

void removelast(linkedlist * ll){
	if (ll->head->next == NULL){
        return;
	}
	node * secondlast = nodesecondlast(ll->head);
	free(secondlast->next);
	secondlast->next = NULL;
    return;
}

node * nodeat(node * current, int index){
    int i = 0;
	while(i < index){
		current = current->next;
		if (current->next == NULL && i != index-1){
            node* invalid;
            data* d = NULL;
            invalid->data = *d;
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

void setdata(data* data, int x, int y, int f, int g, int h, int px, int py){
    data->x = x;
    data->y = y;
    data->f = f;
    data->g = g;
    data->h = h;
    data->px = px;
    data->py = py;
    return;
}

void copydata(data* left, data right){
    left->x = right.x;
    left->y = right.y;
    left->f = right.f;
    left->g = right.g;
    left->h = right.h;
    left->px = right.px;
    left->py = right.py;
    return;
}

data createdata(int x, int y, int f, int g, int h, int px, int py){
    data data;
    data.x = x;
    data.y = y;
    data.f = f;
    data.g = g;
    data.h = h;
    data.px = px;
    data.py = py;
    return data;
}

/*
    Test Methods
*/

void printlist(linkedlist * ll){
	node *current = ll->head;
	while(current->next != NULL){
		printf("%d , %d",current->data.x,current->data.y);
		printf("/n");
		current = current->next;
	}
	printf("%d , %d",current->data.x,current->data.y);
    return;
}