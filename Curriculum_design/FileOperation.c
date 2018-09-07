#include "standard.h"
#include "predefine.h"
#include "FileOperation.h"

InfoNode * FileCheck(InfoNode *head) {
  FILE *fp;
  if ((fp = fopen("database.dat", "rb")) == NULL) {
    num_info = 0;
    puts("Local database file does not exit.");
    if ((fp = fopen("database.dat", "wb")) != NULL) {
      puts("Local database file which named as \"database.dat\" has been created.");
    }
  } else {
    puts("Local database file already exists.");
    int size_info = sizeof(InfoNode);
    InfoNode *current = (InfoNode *)malloc(size_info);
    if (fread(current, size_info, 1, fp)) {
      fclose(fp);
      fp = fopen("database.dat", "rb");
      FileTopointedList(fp, head);
    } else {
      puts("No data exists in the local database file.");
      num_info = 0;
    }
  }
  fclose(fp);
  return head;
}

InfoNode * FileTopointedList(FILE *fp, InfoNode *head) {
  int size_info = sizeof(InfoNode);
  InfoNode *current = (InfoNode *)malloc(size_info);
  InfoNode *pre = NULL;
  while (fread(current, size_info, 1, fp)) {
    if (!head->next) {
      head->next = current;
    }
    pre = current;
    current = (InfoNode *)malloc(size_info);
    pre->next = current;
    num_info++;
  }
  pre->next = NULL;
  free(current);
  return head;
}

void SaveToFile(InfoNode *head) {
  FILE *fp;
  fp = fopen("database.dat", "wb");
  int size_info = sizeof(InfoNode);
  InfoNode *current = head->next;
  while (current) {
    if (fwrite(current, size_info, 1, fp) != 1) {
      puts("Filze write error");
    }
    current = current->next;
  }
  fclose(fp);
}
