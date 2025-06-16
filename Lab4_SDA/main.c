#include <stdio.h>
#include "functions.h"

int main() {
    Node* root = NULL;
    int option, key, age;
    char name[MAX_NAME];
    float salary;

    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Key: "); scanf("%d", &key);
                printf("Name: "); scanf("%s", name);
                printf("Age: "); scanf("%d", &age);
                printf("Salary: "); scanf("%f", &salary);
                root = insertNode(root, key, name, age, salary);
                break;
            case 2:
                printf("Inorder traversal:\n");
                inorder(root);
                break;
            case 3:
                printf("Preorder traversal:\n");
                preorder(root);
                break;
            case 4:
                printf("Postorder traversal:\n");
                postorder(root);
                break;
            case 5:
                printf("Enter key to search: ");
                scanf("%d", &key);
                {
                    Node* found = searchNode(root, key);
                    if (found) {
                        printf("Node found:\n");
                        printNode(found);
                    } else {
                        printf("Node not found.\n");
                    }
                }
                break;
            case 6:
                printf("BFS traversal:\n");
                bfs(root);
                break;
            case 7:
                mirrorTree(root);
                printf("Tree has been mirrored.\n");
                break;
            case 8:
                freeTree(root);
                root = NULL;
                printf("Tree has been cleared.\n");
                break;
            case 9:
                freeTree(root);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 9);

    return 0;
}
