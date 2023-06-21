#include "divisorgraph.h"

int main(int argc, char *argv[]) {
    Vertex* vertexArray[1001]; // Since the index of node start from 1, I don't use index 0 of array for convenience.
    int numvertices = atoi(argv[1]);
    char alg;

    // Greeting message.
    printf("Hello, welcome. Please enter the algorithm you would like to use: \n");
    printf("d - Dijkstra's \n");
    printf("other input - Bellman-Ford \n");
    scanf("%c", &alg);

    // Initialize the graph.   
    initialize(vertexArray);

    //build the graph.
    buildGraph(vertexArray, numvertices);
    findPaths(vertexArray, numvertices, alg);

    finalize(vertexArray);
}
