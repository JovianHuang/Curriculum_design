#ifndef PROCESSFUNCTIONS_H
#define PROCESSFUNCTIONS_H

int FindId(InfoNode *head, long long temp);

bool IdCorrectnessJudgment(InfoNode *head, long long temp);

bool DateCorrectnessJudement(const InfoNode * current);

DateType DayConfirm(DateType year, DateType month);

bool NormalYearConfirm(DateType year);

void CalculateAverage(InfoNode * current);

#endif // !PROCESSFUNCTIONS_H
