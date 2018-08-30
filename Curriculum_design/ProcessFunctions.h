#ifndef PROCESSFUNCTIONS_H
#define PROCESSFUNCTIONS_H

int FindId(InfoNode *head, long long temp);

bool IdCorrectnessJudgment(InfoNode *head, long long temp);

bool DateCorrectnessJudement(const InfoNode * current);

DateType DayConfirm(DateType year, DateType month);

bool NormalYearConfirm(DateType year);

void CalculateAverage(InfoNode * current);

InfoNode * AddInfo(InfoNode * head);

InfoNode * FEntery(InfoNode * head);

InfoNode * InsertNewInfo(InfoNode * head);

InfoNode * BubbleSort(InfoNode * head, DatumEnum datum, bool(*compare)(InfoNode *, InfoNode *, DatumEnum));

void Swap(InfoNode * current, InfoNode * current_next);

bool Asc(InfoNode * a, InfoNode * b, DatumEnum datum);

bool AgeCompare(Date * a, Date * b);

bool Desc(InfoNode * a, InfoNode * b, DatumEnum datum);

#endif // !PROCESSFUNCTIONS_H
