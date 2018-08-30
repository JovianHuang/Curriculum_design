#ifndef OUTPUTFUNCTIONS_H
#define OUTPUTFUNCTIONS_H

InfoNode * PrintList(const InfoNode * head, DatumEnum datum, SortWayEnum sortway);

void PrintInfo(InfoNode * current);

void PrintId(InfoNode * current);

void PrintName(InfoNode * current);

void PrintGender(InfoNode * current);

void PrintDate(InfoNode * current);

void PrintGrade(InfoNode * currrent);

void PrintAverage(InfoNode * current);


#endif // !OUTPUTFUNCTIONS_H
