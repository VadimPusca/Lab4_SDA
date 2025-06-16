#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NAME 50

typedef struct Node {
    int key;
    char name[MAX_NAME];
    int age;
    float salary;

    struct Node* left;
    struct Node* right;
} Node;

#endif
