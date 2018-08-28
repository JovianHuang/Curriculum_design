#include "standard.h"
#include "predefine.h"
#include "OutputFunctions.h"

void PrintInfo(InfoNode *current) {

}

void PrintId(InfoNode *current) {
  printf("Student's ID: %-10lld\n", current->id);
}

void PrintName(InfoNode *current) {
  printf("Student's Name: %-10s\n", current->name);
}
