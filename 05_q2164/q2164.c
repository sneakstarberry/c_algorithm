#include<stdio.h>
#include<stdlib.h>
// 노드 구조체
typedef struct Node{
        int data;
        int cnt;
        struct Node * next;
}       q_Node;

// 전역 변수
int N;
q_Node * H;
q_Node * T;

// 함수 프로토타입
void create(int input);
void push(int input);
int pop();
int empty();

int main(){
        scanf("%d", &N);

	for(int i=1; i<=N; i++){
		push(i);
	}

	while(H!=T){
		int poped;
		pop();
		poped = pop();
		push(poped);
	}

	printf("%d", H->data);

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
        if(empty()){
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

int pop(){
        q_Node * garbage;
	int out;
        if(H == T){
                garbage = H;
                out =  H->data;
                H = NULL;
                T = NULL;
                free(garbage);
                return out;
        } else {
                garbage = H;
		out = H-> data;
                H = H->next;
                free(garbage);
                return out;
        }
}

int empty(){
        if(T == NULL){
                return 1;
        } else {
                return 0;
        }
}

