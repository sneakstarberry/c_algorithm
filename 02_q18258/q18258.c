#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 노드 구조체
typedef struct Node{
	int data;
	int cnt;
	struct Node * next;
}	q_Node;

// 전역 변수
int N;
q_Node * H;
q_Node * T;

// 함수 프로토타입
void create(int input);
void push(int input);
void pop();
void size();
int empty();
void front();
void back();

int main(){
	scanf("%d", &N);
	char c[20];
	H = NULL;
	T = NULL;
	for(int i=0; i<N; i++){
		scanf("%s", c);
		
		if(!strcmp(c, "push")){
			int tmp;
			scanf("%d", &tmp);
			push(tmp);
		} else if(!strcmp(c, "pop")){
			if(empty()){
				printf("-1\n");
			} else {
				pop();
			}
		} else if(!strcmp(c, "size")){
			if(empty()){
				printf("0\n");
			} else{
				size();
			}	
		} else if(!strcmp(c, "empty")){
			printf("%d\n", empty());
		} else if(!strcmp(c, "front")){
			if(empty()){
				printf("-1\n");
			} else{
				front();
			}
		} else if(!strcmp(c, "back")){
			if(empty()){
				printf("-1\n");
			} else{
				back();
			}
		}
	}
	return 0;
}

void create(int input){
	q_Node * node;
	node = malloc(sizeof(q_Node));
	node->data = input;
	node->cnt = 1;
	node->next = NULL;
	
	H = node;
	T = node;
}

void push(int input){
	if(T == NULL){
		create(input);
		return;
	}
	q_Node * node;
	node = malloc(sizeof(q_Node));
	node->data = input;
	node->cnt = T->cnt+1;
	node->next = NULL;
	
	T->next = node;
	T = node;
}

void pop(){
	q_Node * garbage;
	if(H == T){
		garbage = H;
		printf("%d\n", H->data);
		H = NULL;
		T = NULL;
		free(garbage);
		return;
	} else {
		garbage = H;
		printf("%d\n", H->data);
		H = H->next;
		free(garbage);
		return;
	}
} 

void size(){
	printf("%d\n", T->cnt - H->cnt + 1);
}

int empty(){
	if(T == NULL){
		return 1;
	} else {
		return 0;
	}
}

void front(){
	printf("%d\n", H->data);
	return;
}

void back(){
	printf("%d\n", T->data);
	return;
}
