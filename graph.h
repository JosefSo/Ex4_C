#ifndef GRAPH_
#define GRAPH_

#define INFINITY 100000

typedef struct GRAPH_NODE_ *pnode; //for struct Node

//**********************STRUCTURIES*********************//

//-------Edge-------//
typedef struct edge_ {
    int weight;
    pnode dest;
    struct edge_ *next;
} edge, *pedge;
//-------Node-------//
typedef struct GRAPH_NODE_ {
    int nodeId;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;
//-------Dijkstra-------//
typedef struct Dijkstra {
    pnode node;
    int weight;
    int tag;
    struct Dijkstra *next;
} dijkstra, *p_dijkstra;




void TSP(pnode head);

//**********************GRPAH'S FUNCTIONS DECLARATION*********************//
pnode createGraph(int nodes);

void addNode(pnode *head, int src);

pnode getNode(int id, pnode *head);

void addEdge(pnode temp, int dest, int w, pnode *head);

void addNode_B(pnode *head);

void freeEdges(pnode p);

void deleteNode(pnode *head);

void freeGraph(pnode *head);

void freeEdge(pnode *head, int nodeId);

void printGraph(pnode head);


//**********************DIJKSTRA'S FUNCTIONS DECLARATION*********************//
p_dijkstra createDijkstra(pnode start, int src);

p_dijkstra getPointerDijkstra(p_dijkstra head, int id);

void deleteDijkstra(p_dijkstra dijkstra);

p_dijkstra minimalH(p_dijkstra head);

int shortestPath(pnode head, int src, int dest);



#endif //GRAPH_
