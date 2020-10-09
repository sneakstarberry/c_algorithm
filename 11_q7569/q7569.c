#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int fst;
	int sec;
	int trd;
	struct Node * next;
}	q_Node;

int M, N, Z;
int ARR[101][101][101], F[101][101][101];
q_Node *H, *T;

void create(int i, int j, int k);
void push(int i, int j, int k);
void pop();
void scan();

int main() {
	scanf("%d %d %d", &M, &N, &Z);
	int seg=0;
	for(int k=0; k<Z; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				scanf("%d", &ARR[i][j][k]);
				if(ARR[i][j][k] ==1){
					push(i, j, k);
					seg++;
				}
			}
		}
	}
	int ans =0;
	while(H != NULL){
		int dx[6] = {0, 1, 0, -1, 0, 0};
		int dy[6] = {1, 0, -1, 0, 0, 0};
		int dz[6] = {0, 0, 0, 0, 1, -1};
		int cnt=0;
		int traverse = 0;
		for(int j=0; j<seg; j++){
			int pair[3];
			pair[0] = H->fst;
			pair[1] = H->sec;
			pair[2] = H->trd;
			pop();
			
			F[pair[0]][pair[1]][pair[2]] = 1;
			for(int i=0; i<6; i++){
				int newX = pair[0] + dx[i];
				int newY = pair[1] + dy[i];
				int newZ = pair[2] + dz[i];
				if(0<=newY && newY < M && 0<=newX && newX < N && 0<=newZ && newZ < Z)
					if(!F[newX][newY][newZ] && ARR[newX][newY][newZ] ==0){
						ARR[newX][newY][newZ] = 1;
						push(newX, newY, newZ);
						cnt++;
						traverse = 1;
					}
			}
		}
		seg = cnt;
		if(traverse) ans++;
	}
	
	for(int k=0; k<Z; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(ARR[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	printf("%d\n", ans);
}

void create(int i, int j, int k){
	q_Node * node = malloc(sizeof(q_Node));

	node->fst = i;
	node->sec = j;
	node->trd = k;
	node->next = NULL;
	H = node;
	T = node;
}

void push(int i, int j, int k){
	if(H == NULL){
		create(i, j, k);
		return;
	}
	q_Node * node = malloc(sizeof(q_Node));

	node->fst = i;
	node->sec = j;
	node->trd = k;
	node->next = NULL;
	T->next = node;

	T = node;
}

void pop(){
	q_Node * garbage = H;
	H = H->next;
	free(garbage);
}


