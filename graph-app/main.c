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
    insert_edge(graph, 0, 1, 5);
    insert_edge(graph, 0, 2, 6);
    insert_edge(graph, 0, 3, 10);
    //Adega
    insert_edge(graph, 1, 4, 13);
    //Padaria
    insert_edge(graph, 2, 3, 3);
    insert_edge(graph, 2, 4, 11);
    insert_edge(graph, 2, 5, 6);
    //Escola
    insert_edge(graph, 3, 4, 6);    
    insert_edge(graph, 3, 5, 4);
    //Pub
    insert_edge(graph, 4, 6, 3);
    //Universidade
    insert_edge(graph, 5, 6, 8);
    print_distance_matrix(graph, places);

    dijkstra_algorithm(graph, 0, 1, places);
    dijkstra_algorithm(graph, 0, 2, places);
    dijkstra_algorithm(graph, 0, 3, places);
    dijkstra_algorithm(graph, 0, 4, places);
    dijkstra_algorithm(graph, 0, 5, places);
    dijkstra_algorithm(graph, 0, 6, places);

    destroy_graph(&graph);
    return EXIT_SUCCESS;
}

