#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "matrix/matrix.h"

typedef struct _graph {
    int vertices;
    int edges;
    int *vertex_x;
    int *vertex_y;
    int **adjacency;
} graph_t;

static int find_better_distance(float *distance, int *visited, int no_visited);


graph_t *create_graph(int vertices) {
    graph_t *graph = (graph_t *)calloc(1, sizeof(graph_t));
    if(graph == NULL) {
        puts("Graph allocation error");
        exit(EXIT_FAILURE);
    }
    graph->vertices = vertices;
    graph->vertex_x = (int *)calloc(vertices, sizeof(int));
    if(graph->vertex_x == NULL) {
        puts("Graph X vertex allocation error");
        exit(EXIT_FAILURE);
    }
    graph->vertex_y = (int *)calloc(vertices, sizeof(int));
    if(graph->vertex_y == NULL) {
        puts("Graph Y vertex allocation error");
        exit(EXIT_FAILURE);
    }
    graph->edges = 0;
    graph->adjacency = create_matrix(N_ROWS, N_COLUMNS);

    return graph;
}

void insert_edge(graph_t *graph, int v1, int v2, int weight) {
    if(graph->adjacency[v1][v2] == 0) {
        graph->adjacency[v1][v2] = weight;
        graph->adjacency[v2][v1] = weight;
        graph->edges++;
    }
}

void destroy_graph(graph_t **graph) {
    if(*graph == NULL) {
        puts("Invalid Graph");
        return;
    }
    free((*graph)->vertex_x);
    free((*graph)->vertex_y);
    deallocate_matrix((*graph)->adjacency, N_ROWS);
    free(*graph);
    *graph = NULL;
}

void print_distance_matrix(graph_t *graph, const char **places) {
    if(graph == NULL) {
        puts("Invalid Graph");
        return;
    }
    print_matrix(graph->adjacency, N_ROWS, N_COLUMNS, places);
}

int find_better_distance(float *distance, int *visited, int no_visited) {
    int minor = __INT_MAX__;
    int first = 1;

    for(int i = 0; i < no_visited; i++) {
        if(distance[i] < minor && visited[i] == 0) {
            if(first) {
                minor = i;
                first = 0;
            }
            else {
                if(distance[minor] > distance[i])
                    minor = i;
            }
        }
    }
    return minor;
}

void dijkstra_algorithm(graph_t *graph, int vertex_origin, int vertex_destiny, 
                        const char **p) {

    int before[graph->vertices];
    float distance[graph->vertices];
    int count = 0;
    int no_visited = 0;
    int index = 0;
    int *visited = NULL;
    int processed_vertex = 0;

    count = no_visited = graph->vertices;
    visited = (int *)calloc(no_visited, sizeof(int));
    if(visited == NULL) {
        puts("Fail on find_better_way function");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < no_visited; i++) {
        before[i] = -1;
        distance[i] = __INT_MAX__;
        visited[i] = 0;
    }

    distance[vertex_origin] = 0.0f;
    while(count > 0) {
        processed_vertex = find_better_distance(distance, visited, no_visited);
        visited[processed_vertex] = 1;
        count--;
        for(int neighbor = 0; neighbor < graph->vertices; neighbor++) {
            if(graph->adjacency[processed_vertex][neighbor] > 0) {
                index = graph->adjacency[processed_vertex][neighbor] + distance[processed_vertex];

                if(index < distance[neighbor]) {
                    before[neighbor] = processed_vertex;
                    distance[neighbor] = index;
                }
                index = 0;
            }
        }
    }
    printf("From %s to %s is %.2f\n", p[vertex_origin], p[vertex_destiny], distance[vertex_destiny]);
    free(visited);
}