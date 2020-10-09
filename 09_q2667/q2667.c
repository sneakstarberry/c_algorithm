#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	int cnt;
	struct Node * next;
	struct Node * prev;
}	d_Node;

int N, CNT;
char M[25][25];
int F[25][25] = {0,};
d_Node * H;
d_Node * T;

void dfs(int i, int j);
void push(int input);
void create(int input);
void size();
void scan();

int main() {
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%s", M[i]);
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(M[i][j] == '1' && !F[i][j]) {
				CNT =0;
				dfs(i,j);
				push(CNT);
			}
		}
	}

	size();
	scan();
	return 0;
}

void create(int input){
	d_Node * node = malloc(sizeof(d_Node));
	node->data = input;
	node->cnt = 1;
	node->next = NULL;
	node->prev = NULL;

	H = node;
	T = node;
}

void push(int input){
	if(H == NULL){
		create(input);
		return;
	}

	d_Node * node = malloc(sizeof(d_Node));
	node->data = input;
	node->cnt = T->cnt + 1;
	node->next = NULL;
	node->prev = T;

	T->next = node;
	T = node;
}

void size(){
	printf("%d\n", T->cnt);
}

void dfs(int i , int j){
	int dx[4] = {0,1,0,-1};
	int dy[4] = {-1,0,1,0};
	CNT++;
	F[i][j] = 1;
	
	for(int k=0; k<4; k++){
		int newX = i + dx[k];
		int newY = j + dy[k];

		if(0<= newX && newX < N && 0 <= newY && newY < N)
			if(M[newX][newY] == '1'&& !F[newX][newY]) dfs(newX, newY);
	}
}

int compare(const void* first, const void* second){
	int a = *(int *)first;
	int b = *(int *)second;

	if(a < b){
		return -1;
	} else if(a>b){
		return -1;
	} else{
		return 0;
	}
}

void scan(){
	int arr[625];
	int n = T->cnt;
	d_Node * curr = H;
	d_Node * garbage;
	for(int i=0; i< n; i++){
		garbage = curr;
		arr[i] = curr->data;
		curr = curr->next;
		free(garbage);
	}

	qsort(arr, n, sizeof(int), compare );

	for(int i=0; i< n; i++){
		printf("%d\n", arr[i]);
	}
}
