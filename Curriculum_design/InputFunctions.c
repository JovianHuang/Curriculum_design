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

}


