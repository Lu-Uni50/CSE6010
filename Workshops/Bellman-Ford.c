#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
typedef struct Edge
{
    int source, destination, weight;
} Edge;
 
typedef struct Graph
{
    int V, E; // V is number of vertices and E is number of edges
    Edge* edge; // Graph contains Edge
} Graph;
 
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph)); //Allocating space to structure graph
 
	//assigning values to structure elements that taken form user
    graph->V = V;   
    graph->E = E;
    graph->edge = (Edge*) malloc(graph->E * sizeof(Edge) );
	//Creating "Edge" type structures inside "Graph" structure, the number of edge type structures are equal to number of edges
 
    return graph;
}
 
void FinalSolution(int dist[], int n)
{
	// This function prints the final solution
    printf("\nVertex\tDistance from Source Vertex\n");

    for (int i = 0; i < n; ++i){
		printf("%d \t\t %d\n", i, dist[i]);
	}
}
 
void BellmanFord(Graph* graph, int source)
{
    int V = graph->V; 
    int E = graph->E;
	int StoreDistance[V];
 
    // This is initial step that we know , we initialize all distance to infinity except source.
	// We assign source distance as 0(zero)
    for (int i = 0; i < V; i++) {
		StoreDistance[i] = INT_MAX;
	}
    StoreDistance[source] = 0;
 
    //The shortest path of graph that contain V vertices, never contain "V-1" edges. So we do here "V-1" relaxations
    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;

            if (StoreDistance[u] + weight < StoreDistance[v]) {
                StoreDistance[v] = StoreDistance[u] + weight;
			}
        }
    }
 
    /*
	// Actually upto now shortest path found. But BellmanFord checks for negative edge cycle. In this step we check for that
    // shortest distances if graph doesn't contain negative weight cycle.
 
    // If we get a shorter path, then there is a negative edge cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
		int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
 
        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("This graph contains negative edge cycle\n");
    }
	*/
 
    FinalSolution(StoreDistance, V);
 
    return;
}
 
int main()
{
    int V,E,S;  //V = no.of Vertices, E = no.of Edges, S is source vertex
 
	printf("Enter number of vertices in graph\n");
    scanf("%d",&V);
 
	printf("Enter number of edges in graph\n");
    scanf("%d",&E);
 
	printf("Enter your source vertex number\n");
	scanf("%d",&S);
 
    Graph* graph = createGraph(V, E);    //calling the function to allocate space to these many vertices and edges
 
    for(int i=0; i<E; i++) {
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S);
 
    return 0;
}