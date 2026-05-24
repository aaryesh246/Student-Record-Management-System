#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LL.h"

// FIX: Added cgpa parameter
node* addStudent(node* start, char* name, char* id, float cgpa);
node* deleteStudent(node* start, int pos);
int   searchStudent(node* start, char* name);
void  displayRecords(node* start); 

#endif