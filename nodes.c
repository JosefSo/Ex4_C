#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




void deleteNode(pnode *head){
    int num = 0;
    scanf("%d", &num);
    freeEdge(head, num);
    pnode tempNode = *head;
    node *p = NULL;
    if (tempNode->nodeId != num){
        while (tempNode->next->nodeId != num){
            tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next = tempNode->next->next;
        freeEdges(p);
        free(p);
    }
    else{
        p = *head;
        *head = p->next;
        freeEdges(p);
        free(p);
    }
}

/* returns node in the graph with given id */
pnode getNode(int id, pnode *head){
    pnode node_ = *head;

    while (node_ != NULL){
        if (node_->nodeId == id){
            return node_;
        }
        else{
            node_ = node_->next;
        }
    }
    return NULL;
}

/* add node in the graph and also its edges if we get them in input else add only the node */
void addNode(pnode *head, int src){

    int weight, dest;
    pnode node_ = getNode(src, head);
    while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0){
        if (isalpha(dest) || isalpha(weight)){
            break;
        }
        addEdge(node_, dest, weight, head);
    }
}

void addNode_B(pnode *head){
    int weight, src, dest;
    scanf("%d", &src);
    pnode node_ = getNode(src, head);
    if (node_ == NULL){
        pnode connected = *head;
        while (connected->next != NULL){
            connected = connected->next;
        }
        pnode nodeToInsert = (pnode)(malloc(sizeof(node)));
        if (nodeToInsert == NULL)
        {
            perror("there is no enough space to add node, sorry\n");
            exit(0);
        }
        nodeToInsert->nodeId = src;
        nodeToInsert->edges = NULL;
        nodeToInsert->next = NULL;
        connected->next = nodeToInsert;
        
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0){
            if (isalpha(dest) || isalpha(weight)){
                break;
            }
            addEdge(nodeToInsert, dest, weight, head);
        }
    }
    else{
        freeEdges(node_);
        node_->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0){
            if (isalpha(dest) || isalpha(weight)){
                break;
            }
            addEdge(node_, dest, weight, head);
        }
    }
}


