
#include <stdio.h>
#include "STD_Types.h"

#define Null ((void*)0)

typedef struct Node Node;

struct Node{
	u32 data;
	Node *Prev;
	Node *Next;
};

Node *first = Null;
Node *last = Null;

void main(void){
	
	printf("Create: press 1");
	printf("Search: press 2");
	printf("Insert: press 3");
	printf("Delete: press 4");
	printf("Display all: press 5");
	printf("Exit: press 6");
	
}

Node *create(u32 value){
	Node *New = (Node*)malloc(sizeof(Node));
	New->data = value;
	New->Prev = Null;
	New->Next = Null;
	return New;
}

void add(Node *ptr){
	if(first==Null){
		first = last = ptr;
	}else{
		ptr->Prev = last;
		last->Next = ptr;
		last = ptr;
	}
}

void DisaplyAll(void){
	u8 count=0;
	
	Node *display = first;
	
	while(display!=Null){
		count++;
	printf("%d\n", display->data);
	display=display->Next;
	}
	
	printf("number of elemets = %d\n", count);
	
	if(count==0){
		printf("Linked list empty");
	}
	/*if(first==Null){
		printf("Linked list empty");
	}*/
}
Node *search(u32 value){
	Node *search = first;
	while(search!=Null){
		if(search->data == value){
			return search;
		}else{
			search= search->Next;
		}
	}
	return Null;	
}

void insertAfter(Node *after, Node *new){
	new->prev = after;
	new->Next =  after->Next;
	after->Next->prev = new;
	after->Next = new;
}


void delete(Node *delete){
	if(delete==first){
		if(delete==last){
			first = last = Null;
		}else{
			first = first->Next;
			first->Prev = Null;
		}
	}else if(delete == last){
		last=last->Prev;
		last->Next = Null;
	}else{
		delete->Prev->Next = delete->Next;
		delete->Next->Prev = delete->Prev;
	}
	free(delete);
}
