#ifndef FILEOPERATION_H
#define FILEOPERATION_H

InfoNode * FileCheck(InfoNode * head);

InfoNode * FileToLinkedList(FILE * fp, InfoNode * head);

void SaveToFile(InfoNode * head);

#endif // !FILEOPERATION_H
