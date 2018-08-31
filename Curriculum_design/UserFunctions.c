#include "standard.h"
#include "predefine.h"
#include "UserFunctions.h"
#include "ProcessFunctions.h"
#include "OutputFunctions.h"

void DisplayWelcome(void) {
  puts("Welcome to the student achievement management systems.");
}

void DisplayFirstLevelMenu(void) {
  puts("Please choose what to do:");
  puts("A) Add Student Informations\t\t\tD) Delete Student Informations");
  puts("S) Search and Output Student Informations\tM) Modify Student Informations");
  puts("P) Print Out All Existing Data\t\t\tE) Exit This System");
}

void DisplayTheSearchMenu(void) {
  puts("Please select the conditions for information search:");
  puts("a) Output all data in descending order of average");
  puts("b) Output all data in descending order of grade");
  puts("c) Output all data in lexicographic order by name");
  puts("d) Output all data in ascending order of student ID");
  puts("e) Output all data in ascending order of age and gender");
  puts("f) Search and output information based on student name");
  puts("g) Search the highest score of a subject and output");
  puts("h) Search students in a grade interval of a subject and output");
  puts("B) Back to previous");
}

bool YesOrNo(void) {
  bool yes = true;
  char temp;
  while (1) {
    puts("'Y' for 'Yes' and 'N' for 'No'");
    scanf("%c%*c", &temp);
    if (temp != 'Y' && temp != 'N') {
      puts("Invalid input! Please try again.");
    } else if (temp == 'N') {
      yes = false;
      break;
    } else {
      break;
    }
  }
  return yes;
}

InfoNode * EnsureDeleteInfo(InfoNode *head) {
  bool go_on = true;
  char choice;
  while (go_on) {
    puts("Please choose what to do: ");
    puts("D) I am sure I wanna delete an information");
    puts("B) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'D':
      {
        head = DeleteInfo(head);
        break;
      }
      case 'B':
      {
        go_on = false;
        break;
      }
      default:
      {
        puts("Invalid input! Please try again.");
      }
        break;
    }
  }
  return head;
}

InfoNode * EnsureModifyInfo(InfoNode *head) {
  bool go_on = true;
  char choice;
  while (go_on) {
    puts("Please choose what to do:");
    puts("M) I am sure I wanna modify an information.");
    puts("B) Back to previous");
    scanf("%c%*c", &choice);
    switch (choice) {
      case 'M':
      {
        head = ModifyInfo(head);
        break;
      }
      case 'B':
      {
        go_on = false;
        break;
      }
      default:
      {
        puts("Invalid input! Please try again.");
      }
    }
  }
  return head;
}
