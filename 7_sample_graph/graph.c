//Create basic program using C language to implement graph data structure and show basic operations on it.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void display()
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

int main()
{
    int ch;
    create_graph();
    while (1)
    {
        //Display menu
        printf("\n1. Display\n2. Depth First Search\n3. Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        //Case 1: Display the adjacency matrix    
        case 1:
            display();
            break;
        //Case 2: Perform DFS on the graph
        case 2:
            for (int i = 0; i < MAX; i++)
                visited[i] = 0;
            DFS(0);
            break;
        //Case 3: Exit the program
        case 3:
            exit(0);
        //Default case: Invalid choice
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}