#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  int digitsQuantity;
  struct Node *next;
  struct Node *previous;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  int length;
} List;

List *createList() {
  List *list = (List *)malloc(sizeof(List));

  list->head = (Node *)malloc(sizeof(Node));
  list->tail = list->head;
  list->length = 0;

  return list;
}

Node *initializeNode(int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  node->value = value;
  node->next = NULL;
  node->previous = NULL;

  return node;
}

int push(List *list, int value) {
  Node *tmp = list->head;

  Node *node = initializeNode(value);
  node->value = value;

  if (list->length == 0) {
    list->head = node;
  }

  while (tmp->next) {
    tmp = tmp->next;
  }

  node->next = tmp->next;
  node->previous = tmp;
  tmp->next = node;

  list->tail = node;
  list->length++;

  return list->length;
}

int pop(List *list) {
  if (list->length == 0) {
    return list->length;
  }

  Node *tmp = list->head;

  while (tmp->next) {
    tmp = tmp->next;
  }

  Node *newTail = tmp->previous;
  newTail->next = NULL;
  list->tail = newTail;
  free(tmp);

  list->length--;
  return list->length;
}

void print(List *list) {
  if (list->length == 0) {
    printf("ERROR: list is empty\n");
    exit(0);
  }
  Node *tmp = list->head;
  while (tmp) {
    printf("02%d ", tmp->value);
    tmp = tmp->next;
  }

  printf("\n");
}

void printReverse(List *list) {
  if (list->length == 0) {
    printf("ERROR: list is empty\n");
    exit(0);
  }
  Node *tmp = list->tail;
  while (tmp->previous) {
    printf("%02d ", tmp->value);
    tmp = tmp->previous;
  }

  printf("\n");
}

void storeInputInList(List *list, char *input) {
  char *digits = input;
  int inputLength = strlen(digits);

  // inputLength - 3 para ignorar o \0 do final da string
  for (int i = inputLength - 3; i >= 0; i = i - 2) {
    char lastDigits[2];

    strncpy(lastDigits, digits + i, 2);

    int intLastDigits = atoi(lastDigits);
    push(list, intLastDigits);
  }

  if (inputLength % 2 == 0) {
    char lastDigits[2];

    strncpy(lastDigits, digits, 1);

    int intLastDigits = atoi(lastDigits);
    push(list, intLastDigits);
  }

}

void copyList(List *newList, List *oldList) {
  Node *tmp = oldList->head;
  
  while(tmp) {
    push(newList, tmp->value);
    tmp = tmp->next;
  }
}

void clearList(List *list) {
  Node *tmp = list->head;
  
  while(tmp) {
    pop(list);
    tmp = tmp->next;
  }
}
#endif