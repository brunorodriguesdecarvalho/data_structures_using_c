//demonstration of queue operations using C language

#include <stdio.h>
#include <stdlib.h>

//define a struct node
struct node
{
    int data;
    struct node *next;
};

//define a function to print the queue
void print_queue(struct node *head)
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
    //define the head of the queue
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

    //link the third node to the NULL
    third->next = NULL;

    //assign the head of the queue to the first node
    head = first;

    //print the queue
    printf("\n#Initial Queue:\n");
    printf("---------------\n");
    print_queue(head);

    //add a new node to the end of the queue
    struct node *fourth = NULL;
    fourth = (struct node *)malloc(sizeof(struct node));
    fourth->data = 4;
    fourth->next = NULL;
    third->next = fourth;

    //print the queue
    printf("\n#Queue after adding a new node to the end:\n");
    printf("-----------------------------------------\n");
    print_queue(head);

    //remove the first node from the queue
    head = head->next;

    //print the queue
    printf("\n#Queue after removing the first node:\n");
    printf("------------------------------------\n");
    print_queue(head);

    //add a new node to the end of the queue
    struct node *fifth = NULL;
    fifth = (struct node *)malloc(sizeof(struct node));
    fifth->data = 5;
    fifth->next = NULL;
    fourth->next = fifth;

    //print the queue
    printf("\n#Queue after adding a new node to the end:\n");
    printf("-----------------------------------------\n");
    print_queue(head);

    return 0;
}