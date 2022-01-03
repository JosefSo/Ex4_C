#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    p_node temp = NULL;
    p_node *head = &temp;
    char choise;
    char ch;
    int v = 0;
    int src = 0;
    while (scanf("%c", &choise) != EOF)
    {
        if (choise == 'A')
        {
            deleteGraph(head);
            // printf("enter num of verticals:\n");
            scanf("%d", &v);
            *head = createGraph(v);

            scanf("%c", &ch);

            while (scanf("%c", &ch) != 0)
            {
                if (ch == 'n')
                {
                    scanf("%d", &src);
                    addNode(head, src);
                }
                else
                {
                    break;
                }
            }
            // printGraph(*head);
            choise = ch;

            //printf("\nend A func\n");
        }
        if (choise == 'B')
        {
            //printf("\nstart B FUNC\n");
            addNode_B(head);
            //printGraph(*head);
            continue;
        }
        if (choise == 'D')
        {
            // printf("\nstart D FUNC\n");
            deleteNode(head);
            // printGraph(*head);
            continue;
        }
        if (choise == 'S')
        {
            // printf("\nstart S FUNC\n");
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortestPath(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
            //printGraph(*head);
            continue;
        }
        if (choise == 'T')
        {
            // printf("\nstart T FUNC\n");
            TSP(*head);
            // printGraph(*head);
            continue;
        }
    }
    deleteGraph(head);
}
