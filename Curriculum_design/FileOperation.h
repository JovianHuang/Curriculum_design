#ifndef FILEOPERATION_H
#define FILEOPERATION_H

int FileCheck(InfoNode * head);

int FileToLinkedList(FILE * fp, InfoNode * head);

void SaveToFile(InfoNode * head);

#endif // !FILEOPERATION_H
