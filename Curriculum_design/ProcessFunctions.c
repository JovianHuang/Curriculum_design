#include "standard.h"
#include "predefine.h"
#include "InputFunctions.h"
#include "OutputFunctions.h"
#include "ProcessFunctions.h"
#include "FileOperation.h"
#include "LinkedListOperate.h"

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

bool DateCorrectnessJudement(const InfoNode *current) {
  bool correct = false;
  DateType year_temp = current->birthdate.year;
  DateType month_temp = current->birthdate.month;
  DateType day_temp = current->birthdate.day;
  DateType correct_day = DayConfirm(year_temp, month_temp);
  if (year_temp > 2006 || year_temp < 1985) {
    puts("The year should be between 1985-2005. Please re-enter.");
  } else if (month_temp < 1 || month_temp > 12) {
    puts("The month should be between 1-12. Please re-enter");
  } else if (day_temp > correct_day || day_temp < 1) {
    printf("The day should be between 1-&-2d. Please re-enter");
  } else {
    correct = true;
  }
  return correct;
}

DateType DayConfirm(DateType year, DateType month) {
  DateType correct_day = 0;
  DateType arrDays_inLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  DateType arrDays_inNormal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (NormalYearConfirm(year)) {
    correct_day = arrDays_inNormal[month - 1];
  } else {
    correct_day = arrDays_inLeap[month - 1];
  }
  return correct_day;
}

bool NormalYearConfirm(DateType year) {
  bool isNormal = true;
  if ((!year % 4) && year % 10 || !(year % 400)) {
    isNormal = false;
  }
  return isNormal;
}

void CalculateAverage(InfoNode *current) {
  GradeType sum_temp = 0;
  int i;
  for (i = 0; i < (MAXNUM_SCORE - 1); i++) {
    sum_temp = sum_temp + current->grade[i];
  }
  current->grade[Average] = sum_temp / (MAXNUM_SCORE - 1);
}

InfoNode * AddInfo(InfoNode *head) {
  bool go_on = true;
  char choice;
  while (go_on) {
    puts("Please choose what to do:");
    puts("F) First fully entry or full re-enter");
    puts("I) Insert new informations");
    puts("B) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'F':
      {
        num_info = 0;
        head = FEntery(head);
        puts("The following is all the information you just entered.");
        PrintList(head, Id, A);
        break;
      }
      case 'I':
      {
        if (FileCheck(head) == 2) {
          puts("You should save some data in the the local database file first.");
        } else {
          head = InsertNewInfo(head);
          puts("The following is all the information you just entered.");
          PrintList(head, Id, D);
        }
        break;
      }
      case 'B':
      {
        go_on = false;
        break;
      }
      default:
      {
        puts("Invalid input! Please try again.");
      }
    }
  }
  return head;
}

InfoNode * FEntery(InfoNode *head) {
  puts("The action now is to enter the informations for the first time");
  puts("or comepletely re-enter.");
  puts("Please follow the tips below to enter student information.");
  head = CreateList(head);
  return head;
}

InfoNode * InsertNewInfo(InfoNode *head) {
  puts("The action now is to enter the informations for the first time");
  puts("or comepletely re-enter.");
  puts("Please follow the tips below to enter student information.");
  FileCheck(head);
  head = CreateList(head);
  return head;
}

InfoNode * BubbleSort(InfoNode *head, DatumEnum datum, bool(*compare)(InfoNode *, InfoNode*, DatumEnum)) {
  int count = num_info;
  InfoNode *current;
  current = head->next;
  while (count - 1) {
    while (current->next != NULL) {
      if ((*compare)(current, current->next, datum)) {
        Swap(current, current->next);
      }
      current = head->next;
    }
    count--;
    current = head->next;
  }
  return head;
}

void Swap(InfoNode *a, InfoNode *b) {
  InfoNode *temp = a;
  a = b;
  b = temp;
}

bool Asc(InfoNode *a, InfoNode *b, DatumEnum datum) {
  bool isSmaller = true;
  switch (datum) {
    case Id:
    {
      if (a->id > b->id) {
        isSmaller = false;
      }
      break;
    }
    case Name:
    {
      if (strcmp(a->name, b->name) > 1) {
        isSmaller = false;
      }
      break;
    }
    case Average:
    {
      if (a->grade[Average] > b->grade[Average]) {
        isSmaller = false;
      }
      break;
    }
    case Math:
    {
      if (a->grade[Math] > b->grade[Math]) {
        isSmaller = false;
      }
      break;
    }
    case Chinese:
    {
      if (a->grade[Chinese] > b->grade[Chinese]) {
        isSmaller = false;
      }
      break;
    }
    case English:
    {
      if (a->grade[English] > b->grade[English]) {
        isSmaller = false;
      }
      break;
    }
    case Gender:
    {
      if (a->gender && (a->gender ^ b->gender)) {
        isSmaller = false;
      }
      break;
    }
    case Age:
    {
      if (AgeCompare(&a->birthdate, &b->birthdate)) {
        isSmaller = false;
      }
      break;
    }
  }
  return isSmaller;
}

bool AgeCompare(Date *a, Date *b) {
  bool isOlder = true;
  if (a->year > b->year) {
    isOlder = false;
  } else if (a->year == b->year) {
    if (a->month > b->month) {
      isOlder = false;
    } else if (a->month == b->month) {
      if (a->day > b->day) {
        isOlder = false;
      }
    }
  }
  return isOlder;
}

bool Desc(InfoNode *a, InfoNode *b, DatumEnum datum) {
  bool isSmaller = !Asc(a, b, datum);
  return isSmaller;
}