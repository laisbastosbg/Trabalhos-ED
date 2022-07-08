#include <stdio.h>
#include "tree.h"

int main(void) {
  Node *root = NULL;
  root = insert(root, 14);
  root = insert(root, 10);
  root = insert(root, 21);
  root = insert(root, 22);
  root = insert(root, 27);

  preOrder(root);
  printf("\n");
  return 0;
}

