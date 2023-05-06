//demonstrate basic stack operations using C language

#include <stdio.h>
#include <stdlib.h>

//define a struct node
struct node
{
    int data;
    struct node *next;
};

//create basic sample using stack
int main()
{
    //define the top of the stack
    struct node *top = NULL;

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

    //assign the top of the stack to the first node
    top = first;

    //print the stack
    printf("\n#Initial Stack:\n");
    printf("---------------\n");
    printf("top: %d\n", top->data);
    printf("second: %d\n", second->data);
    printf("third: %d\n", third->data);

    //pop the top of the stack
    top = top->next;

    //print the stack
    printf("\n#Stack after pop the top of it\n");
    printf("------------------------------\n");
    printf("top: %d\n", top->data);

    //pop the top of the stack
    top = top->next;

    //print the stack
    printf("\n#Stack after second pop the top of it\n");
    printf("-------------------------------------\n");
    printf("top: %d\n", top->data);

    //pop the top of the stack
    top = top->next;

    //print the stack
    printf("\n#Stack after third pop the top of it\n");
    printf("------------------------------------\n");
    printf("top: %d\n", top->data);

    return 0;
}

