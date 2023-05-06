//create a program in c to show how to use different data structures like array, linked list, stack, queue, tree, graph, hash table, heap, etc.
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

void print_stack(){
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

void print_queue(){
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

void print_tree(struct tree *temp){
    if(temp==NULL){
        return;
    }
    print_tree(temp->left);
    printf("%d ",temp->data);
    print_tree(temp->right);
}

//graph

struct graph{
    int data;
    struct graph *next;
};

struct graph *adj[100];

void add_edge(int u,int v){
    struct graph *temp=(struct graph*)malloc(sizeof(struct graph));
    temp->data=v;
    temp->next=NULL;
    if(adj[u]==NULL){
        adj[u]=temp;
        return;
    }
    struct graph *temp2=adj[u];
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}

void print_graph(int n){
    int i;
    for(i=0;i<n;i++){
        struct graph *temp=adj[i];
        printf("%d: ",i);
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

//hash table

struct hash{
    int data;
    struct hash *next;
};

struct hash *hash_table[100];

void insert_hash(int data){
    struct hash *temp=(struct hash*)malloc(sizeof(struct hash));
    temp->data=data;
    temp->next=NULL;
    int index=data%100;
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

void print_hash(){
    int i;
    for(i=0;i<100;i++){
        struct hash *temp=hash_table[i];
        printf("%d: ",i);
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
    heap[heap_size]=data;
    int i=heap_size;
    heap_size++;
    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent]<heap[i]){
            int temp=heap[parent];
            heap[parent]=heap[i];
            heap[i]=temp;
            i=parent;
        }
        else{
            break;
        }
    }
}

void print_heap(){
    int i;
    for(i=0;i<heap_size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

void delete_heap(){
    heap_size--;
    heap[0]=heap[heap_size];
    int i=0;
    while(i<heap_size){
        int left=2*i+1;
        int right=2*i+2;
        if(left>=heap_size){
            break;
        }
        int max=i;
        if(heap[left]>heap[max]){
            max=left;
        }
        if(right<heap_size && heap[right]>heap[max]){
            max=right;
        }
        if(max==i){
            break;
        }
        int temp=heap[max];
        heap[max]=heap[i];
        heap[i]=temp;
        i=max;
    }
}

//main function with a comment for each operation shown in the screen for end user

int main(){
    int i;
    printf("Array:\n");
    array();
    printf("Linked List:\n");
    linked_list();
    printf("Stack:\n");
    push(1);
    push(2);
    push(3);
    print_stack();
    pop();
    print_stack();
    printf("Queue:\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    print_queue();
    dequeue();
    print_queue();
    printf("Tree:\n");
    insert(3);
    insert(2);
    insert(1);
    insert(4);
    insert(5);
    print_tree(root);
    printf("\n");
    printf("Graph:\n");
    add_edge(0,1);
    add_edge(0,2);
    add_edge(1,2);
    add_edge(2,0);
    add_edge(2,3);
    add_edge(3,3);
    print_graph(4);
    printf("Hash Table:\n");
    insert_hash(1);
    insert_hash(2);
    insert_hash(3);
    insert_hash(101);
    insert_hash(102);
    insert_hash(103);
    print_hash();
    printf("Heap:\n");
    insert_heap(1);
    insert_heap(2);
    insert_heap(3);
    insert_heap(4);
    insert_heap(5);
    print_heap();
    delete_heap();
    print_heap();
    return 0;
}