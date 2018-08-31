#include "standard.h"
#include "predefine.h"
#include "OutputFunctions.h"
#include "FileOperation.h"
#include "ProcessFunctions.h"

InfoNode * PrintList(InfoNode *head, DatumEnum datum, SortWayEnum sortway) {
    switch (sortway) {
      case A:
      {
       head = BubbleSort(head, datum, Asc);
        break;
      }
      case D:
      {
        head = BubbleSort(head, datum, Desc);
        break;
      }
    }
    if (!head->next) {
      puts("NULL");
    } else {
      InfoNode *current = head->next;
      while (current) {
        PrintInfo(current);
        current = current->next;
      }
    }
    printf("\n");
  return head;
}

void PrintInfo(InfoNode *current) {
  PrintId(current);
  PrintName(current);
  PrintGender(current);
  PrintDate(current);
  PrintGrade(current);
  PrintAverage(current);
  printf("\n");
}

void PrintId(InfoNode *current) {
  printf("Student's ID: %-10lld\n", current->id);
}

void PrintName(InfoNode *current) {
  printf("Student's Name: %-10s\n", current->name);
}

void PrintGender(InfoNode *current) {
  if (current->gender) {
    puts("Student's Gender: Male");
  } else {
    puts("Student's Gender: Female");
  }
}

void PrintDate(InfoNode *current) {
  printf("Student's Birthdate: %4d-%02d-%02d\n", current->birthdate.year,
    current->birthdate.month, current->birthdate.day);
}

void PrintGrade(InfoNode *currrent) {
  puts("Student's Grade:");
  printf("Math: %-5.1lf\t", currrent->grade[Math]);
  printf("Chinese: %-5.1lf\t", currrent->grade[Chinese]);
  printf("English: %-5.1lf\n", currrent->grade[English]);
}

void PrintAverage(InfoNode *current) {
  printf("Average: %-5.1lf\n", current->grade[Average]);
}
