#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int data;
	int cnt;
	struct Node * prev;
}	s_Node;

s_Node * H,* L;
int N, X, Y, K, CNT=0;
int MAP[51][51] = {0,}, T[2], F[51][51] = {0,};

void dfs(int x, int y);
void create(int input);
void push(int input);
void size();
void scan();

int main() {
	scanf("%d", &N);
	for(int i=0; i< N; i++){
		scanf("%d %d %d", &X, &Y, &K);
		for(int j=0; j<51; j++){
			memset(MAP[j], 0, sizeof(int) * 51);
			memset(F[j], 0, sizeof(int) * 51);
		}
		
		for(int j=0; j<K; j++){
			scanf("%d %d", &T[0], &T[1]);
			MAP[T[0]][T[1]] = 1;
		}

		for(int j=0; j<X; j++){
			for(int k=0; k<Y; k++){
				if(MAP[j][k] && !F[j][k]){
					CNT=0;
					dfs(j, k);
					push(CNT);
				}
			}
		}
		size();
		scan();
	}
}

void create(int input){
	s_Node * node = malloc(sizeof(s_Node));
	node->prev = NULL;
	node->data = input;
	node->cnt = 1;

	H = node;
	L = node;
}

void push(int input){
	if(H == NULL){
		create(input);
		return;
	}
	s_Node * node = malloc(sizeof(s_Node));
	node->prev = L;
	node->data = input;
	node->cnt = L->cnt+1;
	
	L = node;
}

void size(){
	printf("%d\n", L->cnt);
}

void scan(){
	s_Node * garbage, *curr;
	curr = L;
	while(H == NULL){
		garbage = curr;
		curr = curr->prev;
		free(garbage);
	}
	H = NULL;
	L = NULL;
}

void dfs(int x, int y){
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {-1, 0, 1, 0};

	CNT++;

	F[x][y] = 1;

	for(int m=0; m<4; m++){
		int newX = x + dx[m];
		int newY = y + dy[m];

		if(0<=newX && newX <X && 0<=newY && newY < Y)
			if(MAP[newX][newY] && !F[newX][newY]){
				dfs(newX, newY);
			}
	}
}
