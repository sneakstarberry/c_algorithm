#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	char data;
	struct Node * prev;
}	s_Node;

s_Node * tail;
int N;
bool FLAG=false;

void create(char input){
	s_Node * node;
	node = malloc(sizeof(s_Node));

	node->data = input;
	node->prev = NULL;

	tail = node;
}

void push(char input){
	if(tail == NULL){
		create(input);
		return;
	}
	s_Node * node;
	node = malloc(sizeof(s_Node));

	node->data = input;
	node->prev = tail;

	tail = node;
}

void pop(){
	if(tail == NULL){
		FLAG = true;
		return;
	}

	s_Node * garbage = tail;

	if(tail->prev == NULL){
		tail = NULL;
		free(garbage);
		return;
	}

	tail = tail->prev;
	free(garbage);
}

void order(char input){
	if(input == '('){
		push(input);
	}else if (input == ')'){
		pop();
	}
}

void scan(){
	if(tail != NULL){
		FLAG = true;
	}
} 

void buf_free(){
	s_Node * garbage;
	s_Node * curr;
	curr = tail;
	if(tail->prev == NULL){
		garbage = tail;
		tail = NULL;
		free(garbage);
	}
	while(curr->prev != NULL){
		garbage = curr;
		curr = curr->prev;
		free(garbage);
		if(curr->prev == NULL){
			garbage = curr;
			tail = NULL;
			free(garbage);
		}
	}
	
}

int main(){
	char input;
	scanf("%d", &N);
	scanf("%1c", &input);
	tail = NULL;
	for(int i=0; i<N; i++){
		FLAG=false;
		while(1){
			char glho;
			scanf("%1c", &glho);
			if(glho == '\n'){
				break;
			} else{
				order(glho);
			}
		}
		scan();
		if(FLAG){
			printf("NO\n");
			if (tail != NULL){
				buf_free();
			}
		} else{
			printf("YES\n");
		}
	}

	return 0;
}
