#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	int p;
	struct Node * next;
}	q_Node;

int N;
q_Node * H;
q_Node * T;

int compare(const void *a, const void *b);
void push(int input, int p);
void create(int input, int p);
void clean();
q_Node pop();
void bubble_sort(int *arr, int count);

int main(){
	scanf("%d", &N);
	H = NULL;
	T = NULL;
	for(int i=0; i<N; i++){
		int n;
		int p;
		int c;
		int * arr;
		arr = malloc(sizeof(int) * n);

		scanf("%d %d", &n, &p);

		for(int j=0; j<n; j++){
			int input;
			scanf("%d", &input);
			arr[j] = input;
			if(j == p){
				push(input, 1);
			} else {
				push(input, 0);
			}
		}
		bubble_sort(arr, n);
		int k=1;
		while(1){
			if(arr[k-1] != H->data){
				q_Node tmp;
				tmp = pop();
				push(tmp.data, tmp.p);
			} else {
				if(H->p){
					printf("%d\n", k);
					break;
				}
				pop();
				k++;
			}
		}
		clean();
		free(arr);
	}
	return 0;
}

int compare(const void *a, const void *b){
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1 > num2){
		return -1;
	}

	if(num1 < num2){
		return 1;
	}

	return 0;
}

void create(int input, int p){
	q_Node * node;
	node = malloc(sizeof(q_Node));

	node->data = input;
	node->p = p;
	node->next = NULL;
	
	H = node;
	T = node;
}

void push(int input, int p){
	if(H == NULL){
		create(input, p);
		return;
	}
	q_Node * node;
	node = malloc(sizeof(q_Node));

	node->data = input;
	node->p = p;
	node->next = NULL;

	T->next = node;
	T = node;
}

q_Node pop(){
	q_Node * garbage = H;
	q_Node out = *H;
	if(H == T){
		H = NULL;
		T = NULL;
		free(garbage);
		return out;
	}
	H = H->next;
	free(garbage);

	return out;
}

void clean(){
	if(H == NULL){
		return;
	}else{
		while(H !=NULL){
			pop();
		}
		return;
	}
}

void bubble_sort(int * arr, int count){
    int temp;

    for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
    {
        for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            if (arr[j] < arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // 다음 요소로 보냄
            }
        }
    }
}
