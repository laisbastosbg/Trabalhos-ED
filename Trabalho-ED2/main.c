#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "utils.h"

char *readInput() {
  char *input;
  size_t length = 0;
  ssize_t read;

  read = getline(&input, &length, stdin);
  return input;
}

int main(void) {
  List *list1 = createList();
  List *list2 = createList();

  // lê entrada
  char *input;

  printf("enter first number: ");
  input = readInput();
  storeInputInList(list1, input);

  printf("enter second number: ");
  input = readInput();

  storeInputInList(list2, input);

  List *finalResult = multiply(list1, list2);

  printReverse(finalResult);
  return 0;
}