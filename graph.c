#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



/* function to delete the graph, goes over all
*  edges and then nodes and free their memories */
void freeGraph(pnode *head){
    pnode node_ = *head;
    while (node_ != NULL){
        pedge tempEdge = node_->edges;
        while (tempEdge != NULL){
            pedge tempEdgefree = tempEdge;
            tempEdge = tempEdge->next;
            free(tempEdgefree);
        }
        node *nodeToFree = node_;
        node_ = node_->next;
        free(nodeToFree);
    }
    free(node_);
}

/* function to create the graph with a given number of nodes */
pnode createGraph(int num_nodes){

    node *head = NULL;
    pnode node = NULL;
    pnode temp = NULL;
    
    head = (pnode)malloc(sizeof(node));
    if (head == NULL){
        perror("there is no enough space to create the graph, sorry\n");
        exit(0);
    }
    head->nodeId = 0;
    head->next = NULL;
    head->edges = NULL;
    temp = head;
    
    for (int j = 1; j < num_nodes; j++){
        node = (pnode)malloc(sizeof(node));
        if (node == NULL){
            perror("there is no enough space to create the node, sorry\n");
            exit(0);
        }
        node->nodeId = j;
        node->next = NULL;
        node->edges = NULL;
        temp->next = node;
        temp = temp->next;
    }
    return head;
}

//print fuction in order to check myself (can be deleted)
void printGraph(pnode head){ 
    pnode tempNode = head;
    while (tempNode != NULL)
    {
        printf("Node: %d {", tempNode->nodeId);
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL){
            printf("dest: %d weight: %d ", tempEdge->dest->nodeId, tempEdge->weight);
            tempEdge = tempEdge->next;
        }
        printf("}");
        tempNode = tempNode->next;
    }
}
