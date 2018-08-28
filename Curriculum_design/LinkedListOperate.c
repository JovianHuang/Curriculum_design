#include "standard.h"
#include "predefine.h"
#include "LinkedListOperate.h"
#include "InputFunctions.h"

void FreeMemory(InfoNode *head) {
  InfoNode *prev = head, *current = head->next;
  while (prev) {
    free(prev);
    prev = current;
  }
  if (prev) {
    current = prev->next;
  }
}


InfoNode * HeadNode(void) {
  InfoNode *head;
  head = (InfoNode *)malloc(sizeof(InfoNode));
  if (!head) {
    puts("No enough memory to allocated.");
  } else {
    head->id = 0;
    strcpy(head->name, "NULL");
    head->birthdate.year = head->birthdate.month = head->birthdate.day = 0;
    head->grade[Math] = head->grade[Chinese] = head->grade[English] 
      = head->grade[Average] = 0;
    head->next = NULL;
  }
  return head;
}

InfoNode * NewNode(InfoNode *head) {
  InfoNode *current = (InfoNode *)malloc(sizeof(InfoNode));
  current->next = NULL;
  GetId(head, current);
  GetName(current);


  
  return current;
}