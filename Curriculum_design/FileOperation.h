#ifndef FILEOPERATION_H
#define FILEOPERATION_H

InfoNode * FileCheck(InfoNode * head);

InfoNode * FileTopointedList(FILE * fp, InfoNode * head);

void SaveToFile(InfoNode * head);

#endif // !FILEOPERATION_H
