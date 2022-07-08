#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int getArraySize(int array_pointer, int array_element) {
  return array_pointer / array_element;
}

int main(void) {
  int values[] = {1, 2, 3, 4, 5, 6, 7};
  int start = 0, end = getArraySize(sizeof(values), sizeof(values[0]));

  Node *root = insertToTree(values, start, end-1);

  preOrder(root);
  printf("\n");
  return 0;
}