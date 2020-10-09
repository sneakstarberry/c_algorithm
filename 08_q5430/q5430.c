#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} d_Node;

int F = 0;
int R = 0;
int N;
d_Node *H;
d_Node *T;

void create(int input);
void push(int input);
void pop_f();
void pop_b();
void clean();
void print();

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    char cmd[100001];
    int n;
    scanf("%s", cmd);
    scanf("%d", &n);

    while (1) {
      char t;
      scanf(" %1c", &t);

      if (t == '[' | t == ','){
	int tmp;
	scanf("%d", &tmp);
	push(tmp);
	continue;
      } else if (t == ']')
        break;
    }

    for (int j = 0; j < sizeof(cmd) / sizeof(char); j++) {
      if (cmd[j] == 'R') {
        R = R ? 0 : 1;
      } else if (cmd[j] == 'D') {
        if (n == 0) {
          F = 1;
          break;
        }
        R ? pop_b() : pop_f();
      } else {
        break;
      }
    }

    if (F) {
      printf("error\n");
    } else {
      printf("[");
      print();
      printf("]\n");
    }
    F = 0;
    R = 0;
    clean();
  }
}

void create(int input) {
  d_Node *node = malloc(sizeof(d_Node));
  node->data = input;
  node->next = NULL;
  node->prev = NULL;

  H = node;
  T = node;
}

void push(int input) {
  if (H == NULL) {
    create(input);
    return;
  }
  d_Node *node = malloc(sizeof(d_Node));
  node->data = input;
  node->next = NULL;
  node->prev = T;
  T->next = node;

  T = node;
}

void pop_b() {
  if (H == NULL) {
    F = 1;
    return;
  }
  d_Node *garbage = T;
  if (H == T) {
    H = NULL;
    T = NULL;
    free(garbage);
    return;
  }
  T = T->prev;
  free(garbage);
}

void pop_f() {
  if (H == NULL) {
    F = 1;
    return;
  }
  d_Node *garbage = H;
  if (H == T) {
    H = NULL;
    T = NULL;
    free(garbage);
    return;
  }

  H = H->next;
  free(garbage);
}

void clean() {
  while (H != NULL) {
    pop_b();
  }
}

void print() {
  if (H == NULL) {
    return;
  }
  d_Node *curr = R ? T : H;
  while (1) {
    if (R) {
      if (curr == H) {
        printf("%d", curr->data);
        break;
      }
      printf("%d,", curr->data);
      curr = curr->prev;
    } else {
      if (curr == T) {
        printf("%d", curr->data);
        break;
      }
      printf("%d,", curr->data);
      curr = curr->next;
    }
  }
}
