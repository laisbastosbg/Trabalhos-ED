#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List *getLongerNumber(List *list1, List *list2) {
  if (list1->length >= list2->length) {
    return list1;
  } else {
    return list2;
  }
}

List *getShorterNumber(List *list1, List *list2) {
  if (list1->length < list2->length) {
    return list1;
  } else {
    return list2;
  }
}

void sumRemaining(Node *currentUpperNumber, int remaining) {
  while (remaining > 0) {
    int currentRemaining = remaining % 100;
    int remaining = remaining / 100;

    currentUpperNumber->previous->value += currentRemaining;
  }
}

List *multiply(List *list1, List *list2) {
  Node *lowerNumber = list2->head;

  List *finalResult = createList();
  List *resultRemaining = createList();

  int increaseResultListSizeBy = 0;
  while (lowerNumber) {
    Node *upperNumber = list1->head;
    List *remaining = createList();
    Node *remainingTmp = remaining->head;
    push(remaining, 0);
    List *resultList = createList();

    for (int i = 0; i < increaseResultListSizeBy; i++) {
      push(resultList, 0);
    }
    increaseResultListSizeBy++;

    while (upperNumber) {
      int a = upperNumber->value;
      int b = lowerNumber->value;
      int result = (a * b) + remaining->tail->value;

      int lastTwoDigits = result % 100;
      int remainingDigits = result / 100;

      if (remainingDigits > 0) {
        push(remaining, remainingDigits);
      } else {
        push(remaining, 0);
      }

      push(resultList, lastTwoDigits);
      remainingTmp = remainingTmp->next;
      upperNumber = upperNumber->next;
    }

    /////
    if (remainingTmp->next) {
      push(resultList, remainingTmp->next->value);
    }
    /////
    lowerNumber = lowerNumber->next;

    Node *resultListTmp = resultList->head;
    Node *finalResultTmp = finalResult->head;
    List *finalRemaining = createList();
    Node *finalRemainingTmp = remaining->head;

    if (finalResult->length == 0) {
      copyList(finalResult, resultList);
    } else {
      do {
        int x = 0;
        if (finalResultTmp) {
          x = finalResultTmp->value;
        }
        int y = resultListTmp->value;
        resultListTmp = resultListTmp->next;
        int z = finalRemaining->tail->value;

        int resultSum = x + y + z;

        int rsLastDigits = resultSum % 100;
        int rsRemainingDigits = resultSum / 100;
        if (rsRemainingDigits > 0) {
          push(finalRemaining, rsRemainingDigits);
        } else {
          push(finalRemaining, 0);
        }
        if (finalResultTmp) {
          finalResultTmp->value = rsLastDigits;
          finalResultTmp = finalResultTmp->next;
        } else {
          push(finalResult, rsLastDigits);
        }
      } while (resultListTmp);
    }

  }
  return finalResult;
}