#include <stdio.h>
#include <stdlib.h>
#include "graph/graph.h"

const char *places[] = {
    "Log",
    "Ade",
    "Pad",
    "Esc",
    "Pub",
    "Uni",
    "Cli",
};

int main(void) {
    graph_t *graph = create_graph(7);
    //Log A
    insert_edge(graph, LOG_A, ADEGA, 5);
    insert_edge(graph, LOG_A, PADARIA, 6);
    insert_edge(graph, LOG_A, ESCOLA, 10);
    //Adega
    insert_edge(graph, ADEGA, PUB, 13);
    //Padaria
    insert_edge(graph, PADARIA, ESCOLA, 3);
    insert_edge(graph, PADARIA, PUB, 11);
    insert_edge(graph, PADARIA, UNIV, 6);
    //Escola
    insert_edge(graph, ESCOLA, PUB, 6);    
    insert_edge(graph, ESCOLA, UNIV, 4);
    //Pub
    insert_edge(graph, PUB, CLIENTE, 3);
    //Universidade
    insert_edge(graph, UNIV, CLIENTE, 8);
    print_distance_matrix(graph, places);

    dijkstra_algorithm(graph, LOG_A, ADEGA, places);
    dijkstra_algorithm(graph, LOG_A, PADARIA, places);
    dijkstra_algorithm(graph, LOG_A, ESCOLA, places);
    dijkstra_algorithm(graph, LOG_A, PUB, places);
    dijkstra_algorithm(graph, LOG_A, UNIV, places);
    dijkstra_algorithm(graph, LOG_A, CLIENTE, places);

    destroy_graph(&graph);
    return EXIT_SUCCESS;
}

