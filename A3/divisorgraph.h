#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NUM 1001 //start from 1 so 1001

typedef struct vertex {
    struct vertex * next;
    int v; //vertex id
    int p; // predecessors id
    int w; // weight = 1
    int d; // distance
} Vertex;

void initialize(Vertex** vertexArray);
void buildGraph(Vertex** vertexArray, int numvertices);
void findPaths(Vertex** vertexArray, int numvertices, char bf);
void Dijkstra(Vertex** vertexArray, int numvertices);
void Bellman_Ford(Vertex** vertexArray, int numvertices);
void findmaxpath(Vertex** vertexArray, int numvertices, int arr[]);
void finalize(Vertex** vertexArray);