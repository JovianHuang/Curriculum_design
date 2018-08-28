#include "standard.h"
#include "predefine.h"
#include "InputFunctions.h"
#include "ProcessFunctions.h"

int FindId(InfoNode *head, long long temp) {
  int found = -1, i = 0;
  InfoNode *current = head->next;
  while (current) {
    ++i;
    if (current->id == temp) {
      found = i;
      break;
    }
    current = current->next;
  }
  if (!i) {
    found = i;
  }
  return found;
}

bool IdCorrectnessJudgment(InfoNode *head, long long temp) {
  bool correct = true;
  if (temp <= 0) {
    correct = false;
    puts("ID should be a positive integer, please re-enter.");
  }
  if (FindId(head, temp) < 0) {
    correct = false;
    puts("This ID already exists, please re-enter.");
  }
  return correct;
}