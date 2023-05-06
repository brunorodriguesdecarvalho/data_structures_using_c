//create a program in c to show how to use different data structures like array, linked list, stack, queue, tree, graph, hash table, heap, etc...but let the user choose which data structure to use and display a menu for it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//array
void array(){
    int arr[5];
    int i;
    for(i=0;i<5;i++){
        arr[i]=i;
    }
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//linked list
struct node{
    int data;
    struct node *next;
};

void linked_list(){
    struct node *head=NULL;
    struct node *second=NULL;
    struct node *third=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//stack

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

void push(int data){
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=data;
    temp->next=top;
    top=temp;
}

void pop(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct stack *temp=top;
    top=top->next;
    free(temp);
}

void display(){
    struct stack *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//queue

struct queue{
    int data;
    struct queue *next;
};

struct queue *front=NULL;

void enqueue(int data){
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=data;
    temp->next=NULL;
    if(front==NULL){
        front=temp;
        return;
    }
    struct queue *temp2=front;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}

void dequeue(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct queue *temp=front;
    front=front->next;
    free(temp);
}

void display_queue(){
    struct queue *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//tree

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root=NULL;

void insert(int data){
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
        root=temp;
        return;
    }
    struct tree *temp2=root;
    while(1){
        if(data<temp2->data){
            if(temp2->left==NULL){
                temp2->left=temp;
                return;
            }
            temp2=temp2->left;
        }
        else{
            if(temp2->right==NULL){
                temp2->right=temp;
                return;
            }
            temp2=temp2->right;
        }
    }
}

void inorder(struct tree *temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}

void preorder(struct tree *temp){
    if(temp==NULL){
        return;
    }
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct tree *temp){
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}

//graph

#define MAX 5

int adj[MAX][MAX];
int visited[MAX];

void create_graph()
{
    int i, max_edges, origin, destin;
    printf("Enter number of vertices: ");
    scanf("%d", &max_edges);
    for (i = 0; i < max_edges; i++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ", i + 1);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= max_edges || destin >= max_edges || origin < 0 || destin < 0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
            adj[origin][destin] = 1;
    }
}

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for (j = 0; j < MAX; j++)
        if (!visited[j] && adj[i][j] == 1)
            DFS(j);
}

void display_graph()
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

//hash table

struct hash{
    int data;
    struct hash *next;
};

struct hash *hash_table[10];

void insert_hash(int data){
    struct hash *temp=(struct hash*)malloc(sizeof(struct hash));
    temp->data=data;
    temp->next=NULL;
    int index=data%10;
    if(hash_table[index]==NULL){
        hash_table[index]=temp;
        return;
    }
    struct hash *temp2=hash_table[index];
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}

void display_hash(){
    int i;
    for(i=0;i<10;i++){
        struct hash *temp=hash_table[i];
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

//heap

int heap[100];
int heap_size=0;

void insert_heap(int data){
    heap_size++;
    heap[heap_size]=data;
    int now=heap_size;
    while(heap[now/2]>data){
        heap[now]=heap[now/2];
        now/=2;
    }
    heap[now]=data;
}

void display_heap(){
    int i;
    for(i=1;i<=heap_size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

void delete_heap(){
    int child,parent;
    int data,temp;
    data=heap[heap_size];
    temp=heap[1];
    heap[1]=heap[heap_size];
    heap[heap_size]=temp;
    heap_size--;
    parent=1;
    while(1){
        child=parent*2;
        if(child+1<=heap_size && heap[child]>heap[child+1]){
            child++;
        }
        if(child>heap_size || heap[child]>heap[parent]){
            break;
        }
        temp=heap[child];
        heap[child]=heap[parent];
        heap[parent]=temp;
        parent=child;
    }
}

//menu

void menu(){
    printf("1. Array\n");
    printf("2. Linked List\n");
    printf("3. Stack\n");
    printf("4. Queue\n");
    printf("5. Tree\n");
    printf("6. Graph\n");
    printf("7. Hash Table\n");
    printf("8. Heap\n");
    printf("9. Exit\n");
}

int main()
{
    int ch;
    while (1)
    {
        //Display menu
        menu();
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            array();
            break;
        case 2:
            linked_list();
            break;
        case 3:
            push(1);
            push(2);
            push(3);
            display();
            pop();
            display();
            break;
        case 4:
            enqueue(1);
            enqueue(2);
            enqueue(3);
            display_queue();
            dequeue();
            display_queue();
            break;
        case 5:
            insert(3);
            insert(2);
            insert(1);
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
            postorder(root);
            printf("\n");
            break;
        case 6:
            create_graph();
            display_graph();
            DFS(0);
            break;
        case 7:
            insert_hash(1);
            insert_hash(2);
            insert_hash(3);
            display_hash();
            break;
        case 8:
            insert_heap(3);
            insert_heap(2);
            insert_heap(1);
            display_heap();
            delete_heap();
            display_heap();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
