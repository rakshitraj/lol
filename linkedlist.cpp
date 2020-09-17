#include <iostream>

using namespace std;

struct LinkedList{
    int data;
    LinkedList* next;
};

/**
 * @brief   Function to display linked list
 * @param root  pointer to node of linked list
 * @returns void
 */
void printLinkedList(LinkedList* root)
{
    while(root){
        printf("%d", root->data);
        root = root->next;
    }
}

/**
 * @brief   MAIN function
 * @returns 0 on completion
 */
int main(){
    LinkedList *root, *second, *third;

    root    = new LinkedList;
    second  = new LinkedList;
    third   = new LinkedList;

    root->data = 30;
    root->next = second;

    second->data = 20;
    second->next = third;

    third->data = 10;
    third->next = NULL;

    printLinkedList(root);

    return 0;
}