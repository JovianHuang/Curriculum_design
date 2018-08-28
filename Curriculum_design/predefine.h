#ifndef PREDEFINE_H
#define PREDEFINE_H

#include "predefine.h"

#define MAXNUM_SCORE 4
#define MAXLEN_NAME 20
#define MAXNUM_STUDENTS 31

int num_info;

typedef long long IdType;
typedef char NameType;
typedef bool GenderType;
typedef int DateType;
typedef struct date {
  DateType year;
  DateType month;
  DateType day;
} Date;
typedef double GradeType;

typedef struct infonode {
  IdType id;
  NameType name[MAXLEN_NAME];
  GenderType gender;
  Date birthdate;
  GradeType grade[MAXNUM_SCORE];
  struct infonode *next;
} InfoNode;

typedef enum subjectsenum {
  Math,
  Chinese,
  English,
  Average,
  All
} SubjectsEnum;
typedef enum datumenum {
  Id = 5,
  Name,
  Gender,
  Age,
} DatumEnum;
typedef enum sortwayenum {
  A = 10,
  D
} SortWayEnum;


#endif // !PREDEFINE_H
