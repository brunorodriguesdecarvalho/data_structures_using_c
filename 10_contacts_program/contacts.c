//create a menu with data structure options

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100



typedef struct {
    char name[20];
    char address[30];
    char phone[15];
    char email[30];
} contact;

contact phonebook[MAX];
int n = 0;

void add(){
    printf("Enter name: ");
    scanf("%s", phonebook[n].name);
    printf("Enter address: ");
    scanf("%s", phonebook[n].address);
    printf("Enter phone: ");
    scanf("%s", phonebook[n].phone);
    printf("Enter email: ");
    scanf("%s", phonebook[n].email);
    n++;
}

void display(){
    int i;
    for(i = 0; i < n; i++){
        printf("Name: %s\n", phonebook[i].name);
        printf("Address: %s\n", phonebook[i].address);
        printf("Phone: %s\n", phonebook[i].phone);
        printf("Email: %s\n", phonebook[i].email);
    }
}

void search(){
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    int i;
    for(i = 0; i < n; i++){
        if(strcmp(name, phonebook[i].name) == 0){
            printf("Name: %s\n", phonebook[i].name);
            printf("Address: %s\n", phonebook[i].address);
            printf("Phone: %s\n", phonebook[i].phone);
            printf("Email: %s\n", phonebook[i].email);
            break;
        }
    }
    if(i == n){
        printf("Not found!\n");
    }
}

void update(){
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    int i;
    for(i = 0; i < n; i++){
        if(strcmp(name, phonebook[i].name) == 0){
            printf("Enter new address: ");
            scanf("%s", phonebook[i].address);
            printf("Enter new phone: ");
            scanf("%s", phonebook[i].phone);
            printf("Enter new email: ");
            scanf("%s", phonebook[i].email);
            break;
        }
    }
    if(i == n){
        printf("Not found!\n");
    }
}

void delete(){
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    int i;
    for(i = 0; i < n; i++){
        if(strcmp(name, phonebook[i].name) == 0){
            strcpy(phonebook[i].name, phonebook[n-1].name);
            strcpy(phonebook[i].address, phonebook[n-1].address);
            strcpy(phonebook[i].phone, phonebook[n-1].phone);
            strcpy(phonebook[i].email, phonebook[n-1].email);
            n--;
            break;
        }
    }
    if(i == n){
        printf("Not found!\n");
    }
}

void save(){
    FILE *f = fopen("phonebook.dat", "wb");
    fwrite(phonebook, sizeof(contact), n, f);
    fclose(f);
}

void load(){
    FILE *f = fopen("phonebook.dat", "rb");
    if(f){
        n = fread(phonebook, sizeof(contact), MAX, f);
        fclose(f);
    }
}

int main(){
    int choice;
    load();
    while(true){
        printf("1. Add\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Save\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                delete();
                break;
            case 6:
                save();
                break;
            case 7:
                return 0;
        }
    }
}