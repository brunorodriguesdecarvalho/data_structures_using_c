// Basic sample in C language of a linked list

#include <stdio.h>
#include <stdlib.h>

//define a struct node
struct node
{
    int data;
    struct node *next;
};

//define a function to print the linked list
void print_list(struct node *head)
{
    struct node *current = head;

    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    //define the head of the linked list
    struct node *head = NULL;

    //define the first node
    struct node *first = NULL;

    //define the second node
    struct node *second = NULL;

    //define the third node
    struct node *third = NULL;

    //allocate memory for the first node
    first = (struct node *)malloc(sizeof(struct node));

    //allocate memory for the second node
    second = (struct node *)malloc(sizeof(struct node));

    //allocate memory for the third node
    third = (struct node *)malloc(sizeof(struct node));

    //assign data to the first node
    first->data = 1;

    //assign data to the second node
    second->data = 2;

    //assign data to the third node
    third->data = 3;

    //link the first node to the second node
    first->next = second;

    //link the second node to the third node
    second->next = third;

    //link the third node to NULL
    third->next = NULL;

    //link the head to the first node
    head = first;

    //print the linked list
    print_list(head);

    return 0;
}