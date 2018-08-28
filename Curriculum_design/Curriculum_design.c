/*
* =========================================================================== *
* @Author: 		JovianHuang
* @StudentID:	416125000301
* @Unit:		Class II, CS, School of IE, Hebei GEO University
* @Description:student achievement management system. (Linked List Version)
* @Version:		0.1.0.180827_alpha
* =========================================================================== *
*/
#include "standard.h"
#include "predefine.h"
#include "UserFunctions.h"
#include "LinkedListOperate.h"
#include "InputFunctions.h"
#include "OutputFunctions.h"

int main(void)
{

  // test module
  InfoNode *head, *current;
  head = HeadNode();
  current = NewNode(head);
  PrintDate(current);
  FreeMemory(head);

  // test module


  return 0;
}
