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
typedef struct Queue{
    int items[MAX];
    int front;
    int rear;
}Queue;
Node* createNode(int v){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}
Graph* createGraph(int vertices){
    Graph* graph=(Graph*)malloc(sizeof(Graph));
    graph->numVertices=vertices;

    for (int i=0;i<vertices;i++){
        graph->adjList[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode=createNode(dest);
    newNode->next=graph->adjList[src];
    graph->adjList[src]=newNode;
    newNode=createNode(src);
    newNode->next=graph->adjList[dest];
    graph->adjList[dest]=newNode;
}
Queue* createQueue(){
    Queue*q=(Queue*)malloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isEmpty(Queue* q){
    return (q->rear==-1);
}
void enqueue(Queue* q, int value){
    if (q->rear==MAX-1)
        return;
    if (q->front==-1)
        q->front=0;
    q->rear++;
    q->items[q->rear]=value;
}
int dequeue(Queue* q){
    if (isEmpty(q))
        return -1;
    int item=q->items[q->front];
    q->front++;
    if (q->front>q->rear){
        q->front=q->rear=-1;  
    }
    return item;
}
void bfs(Graph* graph, int startVertex) {
    Queue* q=createQueue();
    graph->visited[startVertex]=1;
    enqueue(q, startVertex);
    printf("BFS Traversal: ");
    while (!isEmpty(q)){
        int currentVertex=dequeue(q);
        printf("%d ", currentVertex);
        Node* temp=graph->adjList[currentVertex];
        while (temp){
            int adjVertex=temp->vertex;
            if (!graph->visited[adjVertex]){
                graph->visited[adjVertex]=1;
                enqueue(q, adjVertex);
            }
            temp=temp->next;
        }
    }
    printf("\n");
}
int main() {
    int vertices=6;
    Graph* graph=createGraph(vertices);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,4);
    addEdge(graph,3,5);
    addEdge(graph,4,5);
    bfs(graph,0);
    return 0;
}