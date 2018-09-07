#ifndef pointedLISTOPERATE_H
#define pointedLISTOPERATE_H

void FreeMemory(InfoNode *head);

InfoNode * CreateHeadNode(void);

InfoNode * CreateNode(InfoNode *head);

void InsertNode(InfoNode * head, InfoNode * current);

InfoNode * CreateList(InfoNode * head);

InfoNode * CopyNode(const InfoNode * source);

InfoNode * CopyList(InfoNode * source);

InfoNode * CreateNode(InfoNode *head);

#endif // !pointedLISTOPERATE_H
