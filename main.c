#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "bst.h"
int main(){
    printf("\n\n\n");
    char name[100];
    char id[100];
    int pos = 0;
    char sname[100];
    float cgpa = 0.0; // FIX: Added variable for cgpa
    printf("----------------------------------------------------------\n");

    node* root = NULL; 

    int quit = 0;
    while(!quit){
        printf("\nChoose any FUNCTIONS: \n\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student by Name\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");

        int ch = 0;
        printf("Enter Choice: ");
        if (scanf("%d", &ch) != 1) { 
            while(getchar() != '\n'); 
            continue; 
        }
        while(getchar() != '\n'); 

        switch (ch){
            case 1:
                printf("Enter name: ");
                if (fgets(name, sizeof(name), stdin) == NULL) break;
                name[strcspn(name, "\n")] = 0; 
                
                printf("Enter id: ");
                if (fgets(id, sizeof(id), stdin) == NULL) break;
                id[strcspn(id, "\n")] = 0; 
                
                // FIX: Prompt for and read the cgpa
                printf("Enter CGPA: ");
                if (scanf("%f", &cgpa) != 1) {
                    printf("Invalid CGPA input.\n");
                    while(getchar() != '\n'); // Clear buffer
                    break;
                }
                while(getchar() != '\n'); // Consume newline after scanf

                // FIX: Pass cgpa to addStudent
                root = addStudent(root, name, id, cgpa);   
                printf("\n");
                displayRecords(root); 
                break;

            case 2:
                printf("Enter the index position to delete (0-based): ");
                if (scanf("%d", &pos) != 1) { 
                    while(getchar() != '\n'); 
                    break; 
                }
                while(getchar() != '\n'); 
                root = deleteStudent(root, pos); 
                printf("\n");
                displayRecords(root); 
                break;

            case 3:
                printf("Enter name to search: ");
                if (fgets(sname, sizeof(sname), stdin) == NULL) break;
                sname[strcspn(sname, "\n")] = 0;
                {
                    node* idx = searchByName(root, sname);
                    if (idx) {
                        // FIX: Updated to show all info
                        printf("Found student -> ID: %s, Name: %s, CGPA: %.2f\n", idx->id, idx->name, idx->cgpa);
                    } else {
                        printf("Student '%s' not found.\n", sname);
                    }
                }
                break;

            case 4:
                displayRecords(root); 
                break;

            case 5:
                freeAllNodes(root);
                quit = 1;
                printf("All records freed. Exiting.\n");
                printf("----------------------------------------------------------\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}