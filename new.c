#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================================
// 1. LINKED LIST STRUCTURE & FUNCTIONS
// ===============================================

// Renamed from LL.h
typedef struct node {
    char* name;
    struct node* next;
} node;

// Helper to create a new linked list node
node* createNode(const char* name) {
    node* new = malloc(sizeof(node));
    if (!new) { perror("malloc node"); exit(1); }

    new->name = strdup(name); // Use strdup for safer memory management
    if (!new->name) { perror("malloc name"); exit(1); }

    new->next = NULL;
    return new;
}

// Fixed function name to 'append'
node* append(node* start, const char* name) {
    node* new = createNode(name);
    if (start == NULL) {
        return new;
    }

    node* curr = start;
    while (curr->next != NULL) curr = curr->next;
    curr->next = new;
    return start;
}

void printList(node* start) {
    int i = 0;
    while (start != NULL) {
        printf("[%d] %s\n", i++, start->name);
        start = start->next;
    }
}

// Frees all linked list nodes and their names
void freeAllListNodes(node* start) {
    node* temp = start;
    while (temp != NULL) {
        node* nxt = temp->next;
        free(temp->name);
        free(temp);
        temp = nxt;
    }
    printf("\n--- Linked list freed ---\n");
}



// The BST node now holds a pointer to the linked list node ('data')
typedef struct tnode {
    struct tnode* left;
    struct tnode* right;
    node* data; 
} tnode;

// Helper to create a new BST node
tnode* createtnode(node* listNode) {
    tnode* new = malloc(sizeof(tnode));
    if (!new) { perror("malloc tnode"); exit(1); }

    new->left = NULL;
    new->right = NULL;
    new->data = listNode; // Store the pointer to the list node

    return new;
}


tnode* insert_bst(tnode* root, node* listNode) {
    if (root == NULL) {
        return createtnode(listNode);
    }

    int cmp = strcmp(listNode->name, root->data->name);

    if (cmp < 0) {
        root->left = insert_bst(root->left, listNode);
    } else if (cmp > 0) {
        root->right = insert_bst(root->right, listNode);
    }
    // If cmp == 0 (duplicate), we don't insert it.

    return root;
}


node* search_bst(tnode* root, const char* key) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(key, root->data->name);

    if (cmp == 0) {
        return root->data; // Found! Return the linked list node
    } else if (cmp < 0) {
        return search_bst(root->left, key);
    } else { // cmp > 0
        return search_bst(root->right, key);
    }
}

// Function to free all temporary BST nodes
void freeAllTnodes(tnode* root) {
    if (root != NULL) {
        freeAllTnodes(root->left);
        freeAllTnodes(root->right);
        // NOTE: We only free the tnode structure, NOT the root->data (list node)
        // as the list node memory is managed by the original linked list.
        free(root);
    }
}


// Builds the BST from the linked list
// Uses a double pointer for the root to modify it in the function call
void init_bst(node* listStart, tnode** bstRootPtr) {
    node* curr = listStart;
    while (curr != NULL) {
        *bstRootPtr = insert_bst(*bstRootPtr, curr);
        curr = curr->next;
    }
}


node* searchByName(node* listStart, const char* targetName) {
    printf("\n--- Starting search for '%s' ---\n", targetName);

    if (!listStart) {
        printf("Error: Linked list is empty.\n");
        return NULL;
    }

    // 1. Build the BST
    tnode* bstRoot = NULL;
    init_bst(listStart, &bstRoot);
    printf("BST built from list nodes.\n");

    // 2. Search the BST
    node* resultNode = search_bst(bstRoot, targetName);
    
    // 3. Clean up the BST (free temporary memory)
    freeAllTnodes(bstRoot);
    printf("BST cleaned up.\n");

    return resultNode;
}


int main() {
    // 1. Build a sample linked list
    node* head = NULL;
    head = append(head, "Brazil");
    head = append(head, "Argentina");
    head = append(head, "Germany");
    head = append(head, "Spain");
    head = append(head, "France");
    head = append(head, "Italy");
    head = append(head, "England");

    printf("Original Linked List:\n");
    printList(head);


    const char* target1 = "Germany";
    node* foundNode1 = searchByName(head, target1);

    if (foundNode1) {
        printf("SUCCESS: Found node with name: %s\n", foundNode1->name);
        // You can now access and use the original linked list node.
    } else {
        printf("FAILURE: Node with name '%s' not found.\n", target1);
    }

    // --- TEST 2: Failed Search ---
    const char* target2 = "Japan";
    node* foundNode2 = searchByName(head, target2);

    if (foundNode2) {
        printf("SUCCESS: Found node with name: %s\n", foundNode2->name);
    } else {
        printf("FAILURE: Node with name '%s' not found.\n", target2);
    }

    // --- Cleanup ---
    freeAllListNodes(head);
    
    return 0;
}