#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

// Create a new node
Node* createNode(int key, char name[], int age, float salary) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->salary = salary;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into the tree
Node* insertNode(Node* root, int key, char name[], int age, float salary) {
    if (root == NULL)
        return createNode(key, name, age, salary);
    if (key < root->key)
        root->left = insertNode(root->left, key, name, age, salary);
    else if (key > root->key)
        root->right = insertNode(root->right, key, name, age, salary);
    return root;
}

// Search for a node by key
Node* searchNode(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}

// Print a node's data
void printNode(Node* node) {
    if (node)
        printf("Key: %d | Name: %s | Age: %d | Salary: %.2f\n",
               node->key, node->name, node->age, node->salary);
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printNode(root);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        printNode(root);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printNode(root);
    }
}

// BFS queue structures
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (!q->rear)
        q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return treeNode;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Breadth-first traversal (BFS)
void bfs(Node* root) {
    if (!root) return;
    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* current = dequeue(q);
        printNode(current);
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    free(q);
}

// Mirror the tree
void mirrorTree(Node* root) {
    if (root) {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
}

// Free memory for the tree
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Print the menu
void menu() {
    printf("\n--- MENU ---\n");
    printf("1. Insert node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Search by key\n");
    printf("6. BFS traversal\n");
    printf("7. Mirror the tree\n");
    printf("8. Clear the tree\n");
    printf("9. Exit\n");
    printf("Choose an option: ");
}
