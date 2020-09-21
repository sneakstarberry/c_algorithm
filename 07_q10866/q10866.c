#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	int cnt;
	struct Node * next;
	struct Node * prev;
}	d_Node;

int N;
d_Node * H;
d_Node * T;

void create(int input);
void push_front(int input);
void push_back(int input);
void pop_front();
void pop_back();
void size();
int empty();
void front();
void back();

int main(){
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		char cmd[20];
		scanf("%s", cmd);
		if(!strcmp(cmd, "push_front")){
			int tmp;
			scanf("%d", &tmp);
			push_front(tmp);
		} else if (!strcmp(cmd, "push_back")){
			int tmp;
			scanf("%d", &tmp);
			push_back(tmp);
		} else if (!strcmp(cmd, "pop_front")){
			if(empty()){
				printf("-1\n");
			} else {
				pop_front();
			}
		} else if (!strcmp(cmd, "pop_back")){
			if(empty()){
				printf("-1\n");
			} else {
				pop_back();
			}
		} else if (!strcmp(cmd, "size")){
			if(empty()){
				printf("0\n");
			} else {
				size();
			}
		} else if (!strcmp(cmd, "empty")){
			printf("%d\n", empty());
		} else if (!strcmp(cmd, "front")){
			if(empty()){
				printf("-1\n");
			} else {
				front();
			}
		} else if (!strcmp(cmd, "back")){
			if(empty()){
				printf("-1\n");
			} else {
				back();
			}
		}
	}
}

void create(int input){
	d_Node * node;
	node = malloc(sizeof(d_Node));

	node->data = input;
	node->cnt = 1;
	node->next = NULL;
	node->prev = NULL;

	H = node;
	T = node;
}

void push_front(int input){
	if(H == NULL){
		create(input);
		return;
	}
	d_Node * node;
	node = malloc(sizeof(d_Node));

	node->data = input;
	node->cnt = H->cnt - 1;
	node->next = H;
	node->prev = NULL;
	H->prev = node;
	H = node;
}

void push_back(int input){
	if(T == NULL){
		create(input);
		return;
	}
	d_Node * node;
	node = malloc(sizeof(d_Node));

	node->data = input;
	node->cnt = T->cnt + 1;
	node->next = NULL;
	node->prev = T;
	T->next = node;
	T = node;
}

void pop_front() {
	printf("%d\n", H->data);

	d_Node * garbage = H;
	if(H == T){
		H = NULL;
		T = NULL;
		free(garbage);
		return;
	}
	H = H->next;

	free(garbage);
}


void pop_back() {
	printf("%d\n", T->data);

	d_Node * garbage = T;
	if(H == T){
		H = NULL;
		T = NULL;
		free(garbage);
		return;
	}
	T = T->prev;

	free(garbage);
}

void size(){
	printf("%d\n", T->cnt - H->cnt + 1);
}

int empty(){
	if(H == NULL){
		return 1;
	} else {
		return 0;
	}
}

void front(){
	printf("%d\n", H->data);
}

void back(){
	printf("%d\n", T->data);
}
