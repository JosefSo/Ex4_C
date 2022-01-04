#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



/* finds edges with node with id=nodeId and removes (free the memory) */
void freeEdge(pnode *head, int nodeId){
    pnode node = *head;
    while (node != NULL){
        if (node->nodeId != nodeId && node->edges != NULL){

            if (node->edges->dest->nodeId != nodeId){
                pedge edge = node->edges;

                while (edge->next != NULL){
                    if (edge->next->dest->nodeId == nodeId){
                        pedge p1 = edge->next;
                        edge->next = edge->next->next;
                        free(p1);
                        break;
                    }
                    edge = edge->next;
                }
            }
            else
            {   
                if (node->edges->next == NULL){
                    pedge p1 = node->edges;
                    node->edges = NULL;
                    free(p1);
                }
                else{
                    pedge p1 = node->edges;
                    node->edges = p1->next;
                    free(p1);
                }
            }
        }
        node = node->next;
    }
}
/* function to add the edge with a given src(our node), dest and weight of edge */
void addEdge(pnode currentNode, int dest, int w, pnode *head){
    // if there are no edges on the current node
    if (currentNode->edges == NULL){
        // allocate memory in size of sruct edge_ and return pointer to this struct
        currentNode->edges = (pedge)malloc(sizeof(edge)); 

        if (currentNode->edges == NULL){
            perror("there is no enough space to add edge, sorry\n");
            exit(0);
        }
        // add edge in empty list
        currentNode->edges->weight = w;
        currentNode->edges->next = NULL;
        node *node = getNode(dest, head);
        currentNode->edges->dest = &(*node);
    }
    else {// if there are edges on the current node
        pedge edgesOfNode = currentNode->edges;
        while (edgesOfNode->next != NULL){
            edgesOfNode = edgesOfNode->next;
        }
        // allocate memory and check if it allocated
        edgesOfNode->next = (pedge)malloc(sizeof(edge));
        if (edgesOfNode->next == NULL){
            perror("there is no enough space to add edge, sorry\n");
            exit(0);
        }
        // add edge in the end of node's list of edges
        edgesOfNode->next->next = NULL;
        edgesOfNode->next->weight = w;
        node *D = getNode(dest, head);
        edgesOfNode->next->dest = &(*D);
    }
}

/* goes over all edges of a give node and free them one by one */
void freeEdges(pnode node){
    if (node->edges != NULL){
        pedge edge = node->edges;

        while (edge != NULL){
            pedge p1 = NULL;
            p1 = edge;
            edge = edge->next;
            free(p1);
        }
    }

    else{ // if it was no edges
        free(node->edges);
    }
}


