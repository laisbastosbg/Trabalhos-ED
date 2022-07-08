#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int value) {
  Node *node = (Node *) malloc(sizeof(Node));
  
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

Node *insertToTree(int values[], int start, int end) {

  if(start > end) return NULL;

  int mid = (start + end) / 2;
  Node *root = createNode(values[mid]);

  root->left = insertToTree(values, start, mid-1);
  root->right = insertToTree(values, mid+1, end);

  return root;
}

void preOrder(Node *node) {
  if (node != NULL) {
    printf("%d ", node->value);
    preOrder(node->left);
    preOrder(node->right);
  }
}