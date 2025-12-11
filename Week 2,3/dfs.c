#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node{
    int vertex;
    struct Node* next;
}Node;
typedef struct Graph{
    int numVertices;
    Node* adjList[MAX];
    int visited[MAX];
}Graph;
Node* createNode(int v){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}
Graph* createGraph(int vertices){
    Graph* graph=(Graph*)malloc(sizeof(Graph));
    graph->numVertices=vertices;
    for (int i=0;i<vertices;i++) {
        graph->adjList[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest){
    Node* newNode=createNode(dest);
    newNode->next=graph->adjList[src];
    graph->adjList[src]=newNode;
    newNode=createNode(src);
    newNode->next=graph->adjList[dest];
    graph->adjList[dest]=newNode;
}
void dfsUtil(Graph* graph,int vertex){
    graph->visited[vertex]=1;
    printf("%d ", vertex);
    Node* temp=graph->adjList[vertex];
    while (temp){
        int adjVertex=temp->vertex;
        if (!graph->visited[adjVertex]){
            dfsUtil(graph, adjVertex);
        }
        temp=temp->next;
    }
}
void dfs(Graph* graph, int startVertex){
    printf("DFS Traversal: ");
    dfsUtil(graph, startVertex);
    printf("\n");
}
int main(){
    int vertices=6;
    Graph* graph=createGraph(vertices);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,4);
    addEdge(graph,3,5);
    addEdge(graph,4,5);
    dfs(graph,0);
    return 0;
}