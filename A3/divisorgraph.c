#include "divisorgraph.h"

// Initialize the node.
void initialize(Vertex** vertexArray) {
    for (int i=0; i<MAX_NUM; i++) {
        vertexArray[i] = (Vertex*) malloc(sizeof(Vertex));
        vertexArray[i]->v = i;
        vertexArray[i]->p = -1; // set unused vex to -1
        vertexArray[i]->d = -INT_MAX; // initial distance       
    }
    vertexArray[1]->p = 0; // first vex's predecessors = 0
    vertexArray[1]->d = 0; // first vex's distance = 0
}

// build the graph
void buildGraph(Vertex** vertexArray, int numvertices) {
    for (int i=1; i<numvertices; i++) {
        Vertex* ptr = vertexArray[i];
        for (int j=i+1; j<=numvertices; j++) {
            if (j%i == 0) {
                ptr->next = (Vertex*) malloc(sizeof(Vertex));
                ptr = ptr->next;
                ptr->v = j;
                ptr->w = 1;
            }
        }
    }
}

void findPaths(Vertex** vertexArray, int numvertices, char bf) {
    int maxdis;
    int arr[2]; // return result to an array

    switch (bf) {
        case 'n':
            Dijkstra(vertexArray, numvertices);
            findmaxpath(vertexArray, numvertices,arr);
            break;
        default: // case for any letters execpt 'n'
            Bellman_Ford(vertexArray, numvertices);
            findmaxpath(vertexArray, numvertices,arr);
            break;
    }
    
    printf("The distance of the longest path in the graph is %d\n", arr[0]);
    
    printf("The longest path is: %d", arr[1]);
    int vex = vertexArray[arr[1]]->p;
    while (vex != -1 && vex != 0) {
        printf(" -> %d", vex);
        vex = vertexArray[vex]->p;
    }
    printf("\n");

}

void Dijkstra(Vertex** vertexArray, int numvertices) {
    int max = -INT_MAX;
    int start = -1; // the start vex
    int end = -1; // the end vex

    for (int i=1; i<=numvertices; i++) {
        if (vertexArray[i]->p != -1) { //used vex
            Vertex* ptr = vertexArray[i];
            while (ptr->next != NULL) { //not reach to the end
                ptr = ptr->next;
                if (vertexArray[ptr->v]->p == -1) { //haven't visited
                    if (vertexArray[i]->d + ptr->w > max) {
                        max = vertexArray[i]->d + ptr->w;
                        start = i;
                        end = ptr->v;
                    }
                    vertexArray[end]->d = max;
                    vertexArray[end]->p = vertexArray[start]->v;
                }
            }
        } 
    }
}

void Bellman_Ford(Vertex** vertexArray, int numvertices) {
    for (int i=1; i<=numvertices; i++) {
        Vertex* ptr = vertexArray[i];
        while (ptr->next != NULL) {
            ptr = ptr->next;
            if (vertexArray[i]->d + ptr->w > vertexArray[ptr->v]->d) {
                vertexArray[ptr->v]->d = vertexArray[i]->d + ptr->w;
                vertexArray[ptr->v]->p = vertexArray[i]->v;
            }
        }
    }
}

void findmaxpath(Vertex** vertexArray, int numvertices, int arr[]){
    int maxdis = -INT_MAX;
    int maxid;

    for (int i = 1; i <= numvertices; i++){
        Vertex* ptr = vertexArray[i];
        if (ptr->d > maxdis) {
            maxdis = ptr->d;
            maxid = i;
        }
    }
    arr[0] = maxdis; //return maximum distance
    arr[1] = maxid; //return the start of the path
    
}

void finalize(Vertex** vertexArray) {
    for (int i=0; i<MAX_NUM; i++) {
        Vertex* ptr = vertexArray[i];
        while (ptr != NULL) {
            Vertex* temp = ptr;
            ptr = ptr->next;
            free((void*)temp);
        }
    }
}