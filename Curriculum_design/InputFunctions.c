#include "standard.h"
#include "predefine.h"
#include "InputFunctions.h"
#include "ProcessFunctions.h"


void GetId(InfoNode *head, InfoNode *current) {
  long long temp;
  do {
    printf("Student's ID: ");
    scanf("%lld%*c", &temp);
  } while (!IdCorrectnessJudgment(head, temp));
  current->id = temp;
}

void GetName(InfoNode *current) {
  printf("Student's Name: ");
  fgets(current->name, MAXLEN_NAME, stdin);
  int len = strlen(current->name);
  current->name[len - 1] = '\0';
}

void GetGender(InfoNode *current) {
  bool go_on = true;
  char temp;
  while (go_on) {
    printf("Student's Gender ('M' for male and 'F' for female): ");
    scanf("%c%*c", &temp);
    switch (temp) {
      case 'M':
      {
        current->gender = true;
        go_on = false;
        break;
      }
      case 'F':
      {
        current->gender = false;
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
}

void GetDate(InfoNode *current) {
  puts("Date of birth (Please enter in this format: yyyy-mm-dd,");
  puts("and the year of birth should be between 1985-2005.");
  puts("The sign '-' between th two numbers is a must.");
  scanf("%d%*c", &current->birthdate.year);
  scanf("%d%*c", &current->birthdate.month);
  scanf("%d%*c", &current->birthdate.day);
}


