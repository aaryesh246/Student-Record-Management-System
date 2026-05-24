#include "student.h"

// FIX: Added cgpa parameter
node* addStudent(node* start, char* name, char* id, float cgpa){
    // FIX: Pass cgpa to append
    start = append(start, name, id, cgpa); 
    printf("Added student %s\n", name);
    return start;
}

node* deleteStudent(node* start, int pos){
    if (pos < 0) {
        printf("Invalid position\n");
        return start;
    }
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (pos == 0) {
        node* temp = start;
        start = start->next;
        if (temp->name) free(temp->name);
        if (temp->id) free(temp->id); 
        free(temp);
        printf("Deleted student at position 0.\n");
        return start;
    }
    node* curr = start;
    int i = 0;
    while (curr != NULL && i < pos - 1) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL || curr->next == NULL) {
        printf("Position outta range,cant DELETE\n");
        return start;
    }
    node* temp = curr->next;
    curr->next = temp->next;
    if (temp->name) free(temp->name);
    if (temp->id) free(temp->id);
    free(temp);
    printf("Deleted student at position %d.\n", pos);
    return start;
}

int searchStudent(node* start, char* name){
    int pos = 0;
    node* curr = start;
    while (curr != NULL) {
        if (curr->name && strcmp(curr->name, name) == 0) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    printf("Not found\n");
    return -1;
}

void displayRecords(node* start){
    print(start);
}