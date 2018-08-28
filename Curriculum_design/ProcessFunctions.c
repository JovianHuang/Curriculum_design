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
  for ( i = 0; i < (MAXNUM_SCORE - 1); i++) {
    sum_temp = sum_temp + current->grade[i];
  }
  current->grade[Average] = sum_temp / (MAXNUM_SCORE - 1);
}
