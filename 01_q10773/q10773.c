#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * prev;
}	s_Node;

s_Node * tail;
int N;

void create(int input){
	s_Node * node;
	node = malloc(sizeof(s_Node));
	node->prev = NULL;
	node->data = input;
	tail = node;
}

void push(int input){
	if(tail == NULL){
		create(input);
	} else{
		s_Node * node;
		node = malloc(sizeof(s_Node));
		node->prev = tail;
		node->data = input;
		tail = node;
	}
}

void pop(){
	s_Node * garbage = tail;
	if(tail->prev == NULL){
		tail = NULL;
		free(garbage);
	} else{
		tail = tail->prev;
		free(garbage);
	}
}

void scan(){
	if(tail == NULL){
		printf("0");
		return;
	}
	s_Node * curr = tail;
	int result = 0;
	while(curr->prev != NULL){
		result+=curr->data;
		s_Node * garbage = curr;
		curr = curr->prev;
		if (curr->prev == NULL){
			result+=curr->data;
		}
		free(garbage);
	}
	printf("%d", result);
}

int main(){
	scanf("%d", &N);

	for(int i=0; i<N;i++){
		int input;
		scanf("%d", &input);

		if(input == 0){
			pop();
		} else{
			push(input);
		}
	}

	scan();

	return 0;
}
