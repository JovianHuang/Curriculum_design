#include "standard.h"
#include "predefine.h"
#include "FileOperation.h"

int FileCheck(InfoNode *head) {
  int status = 1;
  FILE *fp;
  if ((fp = fopen("database.dat", "rb")) == NULL) {
    status = num_info = 0;
    puts("Local database file does not exit.");
    if ((fp = fopen("database.dat", "wb")) != NULL) {
      puts("Local database file which named as \"database.dat\" has been created.");
      status = 1;
    }
  } else {
    puts("Local database file already exists.");
    if (!FileToLinkedList(fo, head)) {
      status = 2;
    }
  }
  fclose(fp);
  return status;
}

int FileToLinkedList(FILE *fp, InfoNode *head) {
  int i = 0, status = 1, flag = 1;
  if (num_info) {
    flag = 0;
    status = 0;
    i = 1;
  }
  int size_info = sizeof(InfoNode);
  InfoNode *current = head->next;
  if (fread(current, size_info, 1, fp)) {
    i++;
    current = current->next;
  }
  if (i < 1) {
    status = 0;
    puts("No data exists in the local database file.");
  }
  if (status) {
    num_info = i - 1;
  }
  if (num_info) {
    status = 1;
  }
  return status;
}

void SaveToFile(InfoNode *head) {
  FILE *fp;
  fp = fopen("datebase.dat", "wb");
  int i;
  int size_info = sizeof(InfoNode);
  InfoNode *current = head->next;
  while (current) {
    fwrite(current, size_info, 1, fp);
    current = current->next;
  }
  fclose(fp);
}
