#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

// Node operations
Node* createNode(int key, char name[], int age, float salary);
Node* insertNode(Node* root, int key, char name[], int age, float salary);
Node* searchNode(Node* root, int key);
void printNode(Node* node);

// Traversals
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void bfs(Node* root);

// Tree operations
void mirrorTree(Node* root);
void freeTree(Node* root);

// Menu display
void menu();

#endif
