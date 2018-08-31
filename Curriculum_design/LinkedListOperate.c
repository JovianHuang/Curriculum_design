#include "standard.h"
#include "predefine.h"
#include "LinkedListOperate.h"
#include "InputFunctions.h"
#include "UserFunctions.h"

void FreeMemory(InfoNode *head) {
  InfoNode *prev = head, *current = head->next;
  while (prev) {
    free(prev);
    prev = current;
    if (prev) {
      current = prev->next;
    }
  }
  
}

InfoNode * CreateHeadNode(void) {
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

InfoNode * CreateNode(InfoNode *head) {
  InfoNode *current = (InfoNode *)malloc(sizeof(InfoNode));
  current->next = NULL;
  GetId(head, current);
  GetName(current);
  GetGender(current);
  GetDate(current);
  GetGrade(current, All);
  return current;
}

void InsertNode(InfoNode *head, InfoNode *current) {
  InfoNode *prev = head, *checked = head->next;
  if (!checked) { // To insert the first node
    prev->next = current;
    current->next = checked;
  } else {
    while (current && checked) { 
      /* To insert the remaining nodes 
      and sort by ascending student's ID */
      if (checked->id < current->id) {
        prev->next = current;
        current->next = checked;
        break;
      } else {
        if (!checked->next) {
          checked->next = current;
          current = current->next;
        } else {
          checked = checked->next;
          prev = prev->next;
        }
      }
    }
  }
}

InfoNode * CreateList(InfoNode * head) {
  bool go_on = true;
  InfoNode *current;
  while (go_on) {
    if (num_info > 30) {
      go_on = false;
      puts("The entry limit has been reached and the entry is terminated.");
    } else {
      current = CreateNode(head);
      puts("Whether to save this data to the list?");
      bool save = YesOrNo();
      if (save) {
        InsertNode(head, current);
        puts("This data has been saved to the list.");
        num_info++;
      } else {
        puts("This data has not been saved to the list.");
      }
      puts("Are you gonna enter next student's information?");
      go_on = YesOrNo();
    }
  }
  puts("Information entry has ended.");
  return head;
}

InfoNode * CopyNode(const InfoNode *source) {
  InfoNode *destination = (InfoNode *)malloc(sizeof(InfoNode));
  destination->id = source->id;
  strcpy(destination->name, source->name);
  destination->gender = source->gender;
  destination->birthdate.year= source->birthdate.year;
  destination->birthdate.month= source->birthdate.month;
  destination->birthdate.day= source->birthdate.day;
  destination->grade[Math] = source->grade[Math];
  destination->grade[Chinese] = source->grade[Chinese];
  destination->grade[English] = source->grade[English];
  destination->grade[Average] = source->grade[Average];
  return destination;
}

InfoNode * CopyList(InfoNode *source) {
  InfoNode *prev = source, *current = source->next;
  InfoNode *new_head = CreateHeadNode();
  InfoNode *new_prev = new_head;
  while (current) {
    InfoNode *new_current = CopyNode(current);
    new_prev->next = new_current;
    new_prev = new_current;
    prev = current;
    current = current->next;
  }
  return new_head;
}
