#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} q_Node;

int N, K,
    ARR[100001] = {
        0,
};
q_Node *H, *T;

void create(int input) {
  q_Node *node = malloc(sizeof(q_Node));
  node->data = input;
  node->next = NULL;

  H = node;
  T = node;
}

void push(int input) {
  if (H == NULL) {
    create(input);
    return;
  }

  q_Node *node = malloc(sizeof(q_Node));
  node->data = input;
  node->next = NULL;
  T->next = node;

  T = node;
}

void pop() {
  q_Node *garbage = H;
  H = H->next;
  free(garbage);
}
int main() {
  scanf("%d %d", &N, &K);

  int seg = 1, cnt, ans=0, flag = 0;
  push(N);
  while (H != NULL) {
    cnt = 0;

    for (int i = 0; i < seg; i++) {
      int data = H->data;
      pop();
      ARR[data] = 1;
      flag = 0;
      if (data == K) {
        printf("%d\n", ans);
        return 0;
      }
      if (data + 1 <= 100000 && !ARR[data + 1]) {
        flag = 1;
        cnt++;
        push(data + 1);
      }
      if (data - 1 >= 0 && !ARR[data -1]) {
        flag = 1;
        cnt++;
        push(data - 1);
      }
      if (data * 2 <= 100000 && !ARR[data * 2] ) {
        flag = 1;
        cnt++;
        push(data * 2);
      }
    }
    seg = cnt;
    if (flag)
      ans++;
  }
  printf("%d\n", ans);
}
