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
#include "ProcessFunctions.h"
#include "FileOperation.h"

int main(void)
{
  DisplayWelcome();
  InfoNode *head, *current;
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
        // AddInfo();
        break;
      }
      case 'D':
      {
        //EnsureDeleteInfo(StuInfo);
        break;
      }
      case 'S':
      {
        //SearchAndOutputInfo(StuInfo);
        break;
      }
      case 'M':
      {
        //EnsureModifyInfo(StuInfo);
        break;
      }
      case 'P':
      {
        //PrintAllInfo(StuInfo, Id, A);
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





  FreeMemory(head);

  return 0;
}
