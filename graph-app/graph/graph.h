#ifndef GRAPH_H
#define GRAPH_H

#define N_ROWS      7
#define N_COLUMNS   7

typedef struct _graph graph_t;

graph_t *create_graph(int vertices);
void insert_edge(graph_t *, int v1, int v2, int weight);
void destroy_graph(graph_t **graph);
void print_distance_matrix(graph_t *graph, const char **places);
void dijkstra_algorithm(graph_t *graph, int vertex_origin, int vertex_destiny, 
                        const char **p);


#endif