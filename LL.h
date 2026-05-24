#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node* next;
    char* name;
    char* id;
    float cgpa; // FIX: Added the cgpa field
} node;

// FIX: Updated prototypes to accept cgpa
node* createNode(char* id, char* name, float cgpa);
node* append(node* start, char* name, char* id, float cgpa);
node* insert(node* start,char* id,  char* name, int pos, float cgpa);
void   print(node* start);
void   freeAllNodes(node* start);

#endif