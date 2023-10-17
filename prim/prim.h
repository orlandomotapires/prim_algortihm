#include "graph.h"
#include "stack.h"

#define num_vertices 4

int adjacency_matrix_a[50][50];
int vis[500];

void read_file_create_graph(Graph **graph, FILE *file);

void print_matrix(int matrix[50][50]);

/*******************
 * Function Implementations
*******************/

void read_file_create_graph(Graph **graph, FILE *file) {
    int a, i = 0;
    char Line[300];

    Graph *node_to_insert, *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    if (fgets(Line, 100, file)) {
        for (a = 0; a < (strlen(Line)); a++) {
            if (Line[a] != ' ') insert_main_list(graph, Line[a]);   
        }
    }

    int weight;
    while (!feof(file) && i < num_vertices) {
        printf("Proximo\n");
        for (a = 0; a < num_vertices; a++) {
            fscanf(file, "%d", &weight);

            if(weight > 0){
                node_to_insert = find_vertex(*graph, a + 1);
                base_node = find_vertex(*graph, (i + 1));

                // printf("nti: %d|%c\n", node_to_insert->weight, node_to_insert->letter);
                // printf("bn: %d|%c\n", base_node->weight, base_node->letter);
                insert_at_end_adj_list(&node_to_insert->main_list, &base_node, weight);
            
                adjacency_matrix_a[i][a] = weight;

                // printf("Valor lido: %d\n", weight);
                printf("matrix: %d\n", adjacency_matrix_a[i][a]);
            }
        }
        i++;
    }
}

void print_matrix(int matrix[50][50]) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void prim(Graph *graph, int num){

}
