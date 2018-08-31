#include "standard.h"
#include "predefine.h"
#include "InputFunctions.h"
#include "OutputFunctions.h"
#include "ProcessFunctions.h"
#include "FileOperation.h"
#include "LinkedListOperate.h"
#include "UserFunctions.h"

InfoNode * FindId(InfoNode *head, long long temp) {
  InfoNode *current = head->next;
  InfoNode *found = NULL;
  while (current) {
    if (current->id == temp) {
      found = current;
      break;
    }
    current = current->next;
  }
  return found;
}

bool IdCorrectnessJudgment(InfoNode *head, long long temp) {
  bool correct = true;
  InfoNode *current = head->next;
  if (current) {
    if (temp <= 0) {
      correct = false;
      puts("ID should be a positive integer, please re-enter.");
    }
    if (FindId(head, temp) != NULL) {
      correct = false;
      puts("This ID already exists, please re-enter.");
    }
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
        if (!FileCheck(head)->next) {
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
  while (count - 1 && current) {
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

InfoNode * DeleteInfo(InfoNode *head) {
  bool go_on = true;
  bool sure = false;
  puts("Please enter the id of the student you want to delete.");
  IdType target_id;
  InfoNode *target = NULL, *target_pre = head;
  while (go_on) {
    scanf("%lld%*c", &target_id);
    target = FindId(head, target_id);
    if (target) {
      PrintInfo(target);
      puts("Please confirm whether to delete this student infomation.");
      sure = YesOrNo();
      if (sure) {
        while (target_pre->next != target) {
          target_pre = target_pre->next;
        }
        target_pre->next = target->next;
        free(target);
        num_info--;
        puts("The following is all existing data.");
        PrintList(head, Id, A);
        go_on = false;
      } else {
        puts("Please confirm whether to continue the delete operation.");
        sure = YesOrNo();
        if (sure) {
          puts("Please enter the id of the student you want to delete.");
        } else {
          go_on = false;
        }
      }
    } else {
      puts("This id does not exist. Please confirm and then enter.");
      puts("Please confirm whether to continue the delete operation.");
      sure = YesOrNo();
      if (sure) {
        puts("Please enter the id of the student you want to delete.");
      } else {
        go_on = false;
      }
    }
  }
  return head;
}

InfoNode * ModifyInfo(InfoNode *head) {
  bool go_on = true, sure = false;
  puts("Please enter the id of the student you want to modify.");
  IdType target_id;
  InfoNode *target = NULL;
  while (go_on) {
    scanf("%lld%*c", &target_id);
    target = FindId(head, target_id);
    if (target) {
      PrintInfo(target);
      puts("Please confirm whether to modify this student infomation.");
      sure = YesOrNo();
      if (sure) {
        head = Modify(head, target);
        puts("The following is all existing data.");
        PrintList(head, Id, A);
        go_on = false;
      } else {
        puts("Please confirm whether to continue the modify operation.");
        sure = YesOrNo();
        if (sure) {
          puts("Please enter the id of the student you want to modify.");
        } else {
          go_on = false;
        }
      }
    } else {
      puts("This id does not exist. Please confirm and then enter.");
      puts("Please confirm whether to continue the modify operation.");
      sure = YesOrNo();
      if (sure) {
        puts("Please enter the id of the student you want to modify.");
      } else {
        go_on = false;
      }
    }
  }
  return head;
}

InfoNode * Modify(InfoNode *head, InfoNode *target) {
  bool go_on = true;
  bool sure = false;
  char choice;
  while (go_on) {
    puts("Please choose which one to modify:");
    puts("I) Id\nN) Name\nG) Gender");
    puts("A) Age\nM) Math garde\nC) Chinese grade");
    puts("E) English grade\nB) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'I':
      {
        GetId(head, target);
        break;
      }
      case 'N':
      {
        GetName(target);
        break;
      }
      case 'G':
      {
        GetGender(target);
        break;
      }
      case 'A':
      {
        GetDate(target);
        break;
      }
      case 'M':
      {
        GetGrade(target, Math);
        break;
      }
      case 'C':
      {
        GetGrade(target, Chinese);
        break;
      }
      case 'E':
      {
        GetGrade(target, English);
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
        break;
      }
    }
    puts("This is the modified data:");
    PrintInfo(head);
    puts("Please confirm whether to continue to modify this student's information.");
    sure = YesOrNo();
    if (!sure) {
      go_on = false;
    }
  }
  return head;
}

InfoNode * SearchAndOutputInfo(InfoNode *head) {
  bool go_on = true;
  char choice;
  while (go_on) {
    DisplayTheSearchMenu();
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'a':
      {
        PrintList(head, Average, D);
        break;
      }
      case 'b':
      {
        head = OrderByGrade(head);
        break;
      }
      case 'c':
      {
        PrintList(head, Name, A);
        break;
      }
      case 'd':
      {
        PrintList(head, Id, A);
        break;
      }
      case 'e':
      {
        head = BubbleSort(head, Gender, Asc);
        InfoNode *temp_female = CopyList(head);
        InfoNode *bound = temp_female->next;
        InfoNode *temp_male = CreateHeadNode();
        while (!bound->gender) {
          if (bound->next->gender) {
            temp_male->next = bound->next;
            bound->next = NULL;
            break;
          }
          bound = bound->next;
        }
        PrintList(temp_female, Age, A);
        PrintList(temp_male, Age, A);
        break;
      }
      case 'f':
      {
        InfoNode *target = SearchName(head);
        if (target) {
          puts("This is the information of the student you are looking for.");
          PrintInfo(target);
        }
        break;
      }
      case 'g':
      {
        head = SearchHighest(head);
        break;
      }
      case 'h':
      {
        head = SearchInGradeInterval(head);
        break;
      }
      case 'B':
      {
        go_on = false;
      }
      default:
      {
        puts("Invalid input! Please try again.");
        break;
      }
    }
  }
  return head;
}

InfoNode * OrderByGrade(InfoNode *head) {
  bool go_on = true;
  char choice;
  while (go_on) {
    puts("Please choose which subject to sort by:");
    puts("M) Math");
    puts("C) Chinese");
    puts("E) English");
    puts("B) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'M':
      {
        PrintList(head, Math, D);
        break;
      }
      case 'C':
      {
        PrintList(head, Chinese, D);
        break;
      }
      case 'E':
      {
        PrintList(head, English, D);
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
        break;
      }
    }
  }
  return head;
}

InfoNode *SearchName(InfoNode *head) {
  InfoNode *target = NULL, *current = head->next;
  char name_target[MAXLEN_NAME];
  bool go_on = true;
  bool sure = false;
  while (go_on) {
    puts("Please enter the name of the student you are looking for.");
    printf("Name: ");
    fgets(name_target, MAXLEN_NAME, stdin);
    int len = strlen(name_target);
    name_target[len - 1] = '\0';
    
    while (current) {
      if (!strcmp(name_target, current->name)) {
        target = current;
        break;
      } else {
        current = current->next;
      }
    }
    if (!target) {
      puts("Sorry, the student you are queried does not exist in the database.");
      puts("Please confirm and re-enter.");
      puts("Please confirm whether to proceed with this operation.");
      sure = YesOrNo();
      if (!sure) {
        go_on = false;
      }
    } else {
      go_on = false;
    }
  }
  return target;
}

InfoNode *SearchHighest(InfoNode *head) {
  DatumEnum datum = Average;
  bool go_on = true;
  char choice;
  InfoNode *current = head->next;
  InfoNode *target[MAXNUM_STUDENTS] = {NULL};
  while (go_on) {
    puts("Please select a query subject:");
    puts("M) Math");
    puts("C) Chinese");
    puts("E) English");
    puts("B) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'M':
      {
        datum = Math;
        break;
      }
      case 'C':
      {
        datum = Chinese;
        break;
      }
      case 'E':
      {
        datum = English;
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
        break;
      }
    }
    if (choice == 'M' || choice == 'C' || choice == 'E') {
      head = BubbleSort(head, datum, Desc);
      current = head->next;
      GradeType highest = current->grade[datum];
      int i = 0;
      target[i] = current;
      while (current) {
        if (current->grade[datum] != highest) {
          break;
        } else {
          target[++i] = current;;
          current = current->next;
        }
      }
      for (i = 0; i < num_info; i++) {
        if (target[i] && !i) {
          puts("The following is the highest score winner's information:");
          if (target[i]) {
            PrintInfo(target[i]);
          } else {
            break;
          }
        }
      }
    }
  }
  return head;
}

InfoNode *SearchInGradeInterval(InfoNode *head) {
  bool go_on = true;
  bool sure = false;
  char choice;
  DatumEnum datum = Average;
  while (go_on) {
    puts("Please select a query subject:");
    puts("M) Math");
    puts("C) Chinese");
    puts("E) English");
    puts("B) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'M':
      {
        datum = Math;
        break;
      }
      case 'C':
      {
        datum = Chinese;
        break;
      }
      case 'E':
      {
        datum = English;
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
        break;
      }
    }
    head = InGradeInterval(head, datum);
    puts("Please confirm whether to continue this operation");
    sure = YesOrNo();
    if (!sure) {
      go_on = false;
    }
  }
  return head;
}

InfoNode *InGradeInterval(InfoNode *head, DatumEnum datum) {
  int interval[2];
  InfoNode *current = head->next;
  bool found = false;
  puts("Please enter a score interval in a format similar to 30-80:");
  puts("The '-' between the two numbers is a must.");
  puts("The number behind must be larger than the previous one.");
  scanf("%d%*c%d%*c", &interval[0], &interval[1]);
  head = BubbleSort(head, datum, Desc);
  int counter = 0;
  while (current) {
    if (current->grade[datum] <= interval[1]) {
      if (current->grade[datum] >= interval[0]) {
        if (!current) {
          puts("The following are eligible data:");
          counter++;
        }
        PrintInfo(current);
        found = true;
      }
    }
    current = current->next;
  }
  if (!found) {
    puts("The score of this subject without any student is in this interval");
  } else {
    if (counter == 1) {
      printf("A total of %d student is eligible.", counter);
    } else {
      printf("A total of %d students are eligible.", counter);
    }
  }
  return head;
}

