#include "bst.h"
#include"LL.h"
#include <stdio.h>
#include <string.h>

// ===============================================
// Internal BST Structure & Functions
// These are not exposed in bst.h
// ===============================================

// Internal BST node structure. Stores a pointer to the original list node.
typedef struct tnode {
    struct tnode* left;
    struct tnode* right;
    node* data; // Pointer to the linked list node
} tnode;

// Helper to create a new BST node
static tnode* createtnode(node* listNode) {
    tnode* new = malloc(sizeof(tnode));
    if (!new) { perror("malloc tnode"); exit(EXIT_FAILURE); }

    new->left = NULL;
    new->right = NULL;
    new->data = listNode; 

    return new;
}

// Recursive BST Insertion based on string comparison
static tnode* insert_bst(tnode* root, node* listNode) {
    if (root == NULL) {
        return createtnode(listNode);
    }

    // Use strcmp to compare names
    int cmp = strcmp(listNode->name, root->data->name);

    if (cmp < 0) {
        root->left = insert_bst(root->left, listNode);
    } else if (cmp > 0) {
        root->right = insert_bst(root->right, listNode);
    }
    // Ignore duplicates (cmp == 0)

    return root;
}

// Recursive BST Search
static node* search_bst(tnode* root, const char* key) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(key, root->data->name);

    if (cmp == 0) {
        return root->data; // Found! Return the linked list node pointer
    } else if (cmp < 0) {
        return search_bst(root->left, key);
    } else { // cmp > 0
        return search_bst(root->right, key);
    }
}

// Function to free all temporary BST nodes
static void freeAllTnodes(tnode* root) {
    if (root != NULL) {
        freeAllTnodes(root->left);
        freeAllTnodes(root->right);
        free(root);
    }
}

// Builds the BST from the linked list
static void init_bst(node* listStart, tnode** bstRootPtr) {
    node* curr = listStart;
    while (curr != NULL) {
        *bstRootPtr = insert_bst(*bstRootPtr, curr);
        curr = curr->next;
    }
}



node* searchByName(node* listStart, const char* targetName) {
    printf("\n--- Starting fast search for '%s' ---\n", targetName);

    if (!listStart) {
        printf("Error: Linked list is empty.\n");
        return NULL;
    }

    // 1. Build the temporary BST
    tnode* bstRoot = NULL;
    init_bst(listStart, &bstRoot);


    // 2. Search the BST
    node* resultNode = search_bst(bstRoot, targetName);
    
    // 3. Clean up the BST (free temporary memory)
    freeAllTnodes(bstRoot);
   

    return resultNode;
}