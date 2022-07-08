#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int value;
  int height;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int value) {
  Node *node = (Node *) malloc(sizeof(Node));
  
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  
  return node;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int height(Node *node) {
  if (node == NULL) {
    return 0;
  }
  
  return 1 + max(height(node->left), height(node->right));
}

int getBalance(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return height(node->left) - height(node->right);
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *z = y->left;

  y->left = x;
  x->right = z;

  x->height = height(x);
  y->height = height(y);

  return y;
}

Node *rightRotate(Node *x) {
  Node *y = x->left;
  Node *z = y->right;

  y->right = x;
  x->left = z;

  x->height = height(x);
  y->height = height(y);

  return y;
}

Node *insert(Node *node, int value) {
  if(node == NULL) {
    return createNode(value);
  }

  if(value < node->value) {
    node->left = insert(node->left, value);
  } else if(value > node->value) {
    node->right = insert(node->right, value);
  } else {
    return node;
  }

  node->height = height(node);

  int balance = getBalance(node);

  if (balance > 1 && value < node->left->value)
    return rightRotate(node);

  if (balance < -1 && value > node->right->value)
    return leftRotate(node);

  if (balance > 1 && value > node->left->value)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && value < node->right->value)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}


void preOrder(Node *root) {
  if(root != NULL) {
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
  }
}
