/*
* =========================================================================== *
* @Author: 		JovianHuang
* @StudentID:	416125000301
* @Unit:		Class II, CS, School of IE, Hebei GEO University
* @Description:student achievement management system. (pointed List Version)
* @Version:		1.9.21.180903_alpha
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

int main(void) {
  DisplayWelcome();
  InfoNode *head;
  head = CreateHeadNode();
  head = FileCheck(head);
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
        SaveToFile(head);
        FreeMemory(head);
        exit(1);
      }
      default:
      {
        puts("Invalid input! Please try again.");
        break;
      }
    }
  }
  return 0;
}
