#include "LL.h"

// FIX: Added cgpa parameter
node* createNode(char* id, char* name, float cgpa){
    node* new = malloc(sizeof(node));
    if (!new) { perror("malloc"); exit(1); }

    new->name = malloc(strlen(name) + 1);
    if (!new->name) { perror("malloc"); free(new); exit(1); }
    strcpy(new->name, name);

    new->id = malloc(strlen(id) + 1);
    if (!new->id) { perror("malloc"); free(new->name); free(new); exit(1); }
    strcpy(new->id, id);
    
    new->cgpa = cgpa; // FIX: Assign the cgpa
    new->next = NULL;
    return new;
}

// FIX: Added cgpa parameter
node* append(node* start,  char* name, char* id, float cgpa){
    // FIX: Pass cgpa to createNode
    node* new = createNode(id, name, cgpa);
    if (start == NULL) {
        return new;
    }

    node* curr = start;
    while (curr->next != NULL) curr = curr->next;
    curr->next = new;
    return start;
}

// FIX: Added cgpa parameter
node* insert(node* start, char* id, char* name, int pos, float cgpa){
    // FIX: Pass cgpa to createNode
    node* new = createNode(id, name, cgpa);
    if (pos < 0) {
        printf("invalid\n");
        free(new->name); free(new->id); free(new);
        return start;
    }

    if (pos == 0 || start == NULL) {
        new->next = start;
        return new;
    }

    node* curr = start;
    int i = 0;
    while (curr != NULL && i < pos - 1) {
        curr = curr->next;
        i++;
    }
    if (curr == NULL) {
        printf("position outta range, Cant INSERT\n");
        free(new->name); free(new->id); free(new);
        return start;
    }
    new->next = curr->next;
    curr->next = new;
    return start;
}

void print(node* start){
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    while (start != NULL) {
        // FIX: Added CGPA to the print statement, formatted to 2 decimal places
        printf("  ID: %-10s | Name: %-20s | CGPA: %.2f\n", start->id, start->name, start->cgpa);
        start = start->next;
    }
    printf("-----------------------\n");
}

void freeAllNodes(node* start){
    node* temp = start;
    while (temp != NULL) {
        node* nxt = temp->next;
        if (temp->name) free(temp->name);
        if (temp->id) free(temp->id); 
        free(temp);
        temp = nxt;
    }
}