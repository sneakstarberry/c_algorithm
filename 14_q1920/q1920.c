#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * left;
	struct Node * right;
}	t_Node;

t_Node * root;

int N, M, X[100001];

void push(int input){
	if(root == NULL){
		t_Node * node = malloc(sizeof(t_Node));
		node->data = input;
		node->left = NULL;
		node->right = NULL;
		root = node;
		return;
	}
	t_Node * t = root;
	while(1) {
		t_Node * node = malloc(sizeof(t_Node));
		if (t->data > input){
			if(t->left == NULL){
				node->data = input;
				node->left = NULL;
				node->right = NULL;
				t->left = node;
				return;
			}

			t = t->left;
		} else if (t->data < input){
			if(t->right == NULL){
				node->data = input;
		 		node->left = NULL;
				node->right = NULL;
				t->right = node;
				return;
			}

			t = t->right;
		}
	}
}

void scan(int input){
	t_Node * t = root;
	int ans = 0;
	while(t!=NULL){
		if (t->data == input){
			printf("1");
			return;
		}
		if(t->data < input){
			if(t->right == NULL) break;
			t = t->right;
		}
		if(t->data > input){
			if(t->left == NULL)break;
			t = t->left;
		}
	}
	printf("0");
	return;
}

void trash(t_Node * node){
	t_Node * r = node->right;
	t_Node * l = node->left;
	if(r != NULL){
		trash(r);
	}
	if(l != NULL){
		trash(l);
	}
	free(node);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int tmp;
		scanf("%d\n", &tmp);
		push(tmp);
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d\n", &X[i]);
		scan(X[i]);
	}
	trash(root);
	return 0;
}
