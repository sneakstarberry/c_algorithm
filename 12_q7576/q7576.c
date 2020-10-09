#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
        int fst;
        int sec;
        struct Node * next;
}       q_Node;

int M, N;
int ARR[1001][1001], F[1001][1001];
q_Node *H, *T;

void create(int i, int j);
void push(int i, int j);
void pop();
void scan();

int main() {
        scanf("%d %d", &M, &N);
        int seg=0;
        for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                        scanf("%d", &ARR[i][j]);
                        if(ARR[i][j] ==1){

                                push(i, j);
                                seg++;
                        }
                }
        }
        int ans =0;
        while(H != NULL){
                int dx[4] = {0, 1, 0, -1};
                int dy[4] = {1, 0, -1, 0};
                int cnt=0;
                int traverse = 0;
                for(int j=0; j<seg; j++){
                        int pair[2];
                        pair[0] = H->fst;
                        pair[1] = H->sec;
                        pop();

                        F[pair[0]][pair[1]] = 1;
                        for(int i=0; i<4; i++){
                                int newX = pair[0] + dx[i];
                                int newY = pair[1] + dy[i];
                                if(0<=newY && newY < M && 0<=newX && newX < N)
                                        if(!F[newX][newY] && ARR[newX][newY] ==0){
                                                ARR[newX][newY] = 1;
                                                push(newX, newY);
                                                cnt++;
                                                traverse = 1;
                                        }
                        }
                }
                seg = cnt;
                if(traverse) ans++;
        }

        for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                        if(ARR[i][j] == 0) {
                                printf("-1\n");
                                return 0;
                        }
                }
        }

        printf("%d\n", ans);
}

void create(int i, int j){
        q_Node * node = malloc(sizeof(q_Node));

        node->fst = i;
        node->sec = j;
        node->next = NULL;
        H = node;
        T = node;
}

void push(int i, int j){
        if(H == NULL){
                create(i, j);
                return;
        }
        q_Node * node = malloc(sizeof(q_Node));

        node->fst = i;
        node->sec = j;
        node->next = NULL;
        T->next = node;

        T = node;
}

void pop(){
        q_Node * garbage = H;
        H = H->next;
        free(garbage);
}

