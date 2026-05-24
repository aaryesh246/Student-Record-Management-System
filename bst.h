#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include"LL.h"
// ===============================================
// Public Linked List Structure
// The BST functions require this structure definition
// to operate on the list nodes.
// ===============================================

node* searchByName(node* listStart, const char* targetName);

#endif // BST_H