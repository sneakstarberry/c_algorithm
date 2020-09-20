#include<stdio.h>
#include<stdlib.h>

// 숫자 스택
typedef struct Node{
	int data;
	struct Node * prev;
}	i_Node;

// char 스택
typedef struct c_Node{
	char data;
	struct c_Node * prev;
	struct c_Node * next;
}	c_Node;

// 전역 변수
int N, arr[100001]={0,};
i_Node * Head;
i_Node * Tail;
c_Node * c_Head;
c_Node * c_Tail;

// 함수 프로토 타입
void create(int input);
void push(int input);
void pop();
void c_create(char input);
void c_push(char input);
void c_print();
int empty();

int main(){
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	int j = 0;
	for(int i=1; i<=N; i++){
		push(i);
		c_push('+');
		while(!empty() && Tail->data == arr[j]){
			pop();
			c_push('-');
			j++;
		}
	}
	if(!empty()){
		printf("NO\n");
	}else{
		c_print();
	}
	return 0;
}

void create(int input){
	i_Node * node;
	node = malloc(sizeof(i_Node));
	node->data = input;
	node->prev = NULL;
	Head = node;
	Tail = node;
}

void push(int input){
	if (Tail == NULL){
		create(input);
		return;
	}
	
	i_Node * node;
	node = malloc(sizeof(i_Node));
	node->data = input;
	node->prev = Tail;
	Tail = node;
}

void pop(){
	i_Node * garbage = Tail;
	if(Tail->prev == NULL){
		Tail = NULL;
		free(garbage);
		return;
	}
	Tail = Tail->prev;
	free(garbage);
} 

int empty(){
	if(Tail == NULL){
		return 1;
	} else {
		return 0;
	}
}

void c_create(char input){
	c_Node * node;
	node = malloc(sizeof(c_Node));
	node->data = input;
	node->prev = NULL;
	node->next = NULL;
	c_Head = node;
	c_Tail = node;
}

void c_push(char input){
	if(c_Tail== NULL){
		c_create(input);
		return;
	}
	c_Node * node;
	node = malloc(sizeof(c_Node));
	node->data = input;
	node->prev = c_Tail;
	c_Tail->next = node;
	c_Tail = node;
}

void c_print(){
	c_Node * curr = c_Head;
	c_Node * garbage;
	while(1){
		printf("%c", curr->data);
		garbage = curr;
		curr = curr->next;
		free(garbage);

		if(curr == c_Tail){
			printf("%c\n", curr->data);
			free(curr);
			return;
		}
	}
}
