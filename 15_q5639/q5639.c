#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * left;
	struct Node * right;
}	t_Node;

t_Node * root;
void push(int num);
void post_order(t_Node * node);
int main(){
	int tmp;
	while(scanf("%d", &tmp) != EOF){
		push(tmp);
	}
	post_order(root);
	root = NULL;

	return 0;
}

void post_order(t_Node * node){
	if(node !=NULL){
		post_order(node->left);
		post_order(node->right);
		t_Node * garbage;
		garbage = node;
		printf("%d\n", node->data);
		free(garbage);
	}
}

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

