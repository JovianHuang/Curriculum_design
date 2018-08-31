/*
* =========================================================================== *
* @Author: 		JovianHuang
* @StudentID:	416125000301
* @Unit:		Class II, CS, School of IE, Hebei GEO University
* @Description:student achievement management system. (Linked List Version)
* @Version:		1.8.11.180831_alpha
* =========================================================================== *
*/
#include "standard.h"
#include "predefine.h"
#include "UserFunctions.h"
#include "LinkedListOperate.h"
#include "InputFunctions.h"
#include "OutputFunctions.h"
#include "ProcessFunctions.h"
#include "FileOperation.h"
#include "ProcessFunctions.h"

int main(void)
{
  DisplayWelcome();
  InfoNode *head;
  head = CreateHeadNode();
  FileCheck(head);
  bool go_on = true;
  char choice;
  while (go_on) {
    DisplayFirstLevelMenu();
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'A':
      {
        head = AddInfo(head);
        break;
      }
      case 'D':
      {
        head = EnsureDeleteInfo(head);
        break;
      }
      case 'S':
      {
        head = SearchAndOutputInfo(head);
        break;
      }
      case 'M':
      {
        head = EnsureModifyInfo(head);
        break;
      }
      case 'P':
      {
        head = PrintList(head, Id, A);
        break;
      }
      case 'E':
      {
        exit(1);
      }
      default:
      {
        puts("Invalid input! Please try again.");
        break;
      }
    }
  }
  SaveToFile(head);
  FreeMemory(head);
  return 0;
}
