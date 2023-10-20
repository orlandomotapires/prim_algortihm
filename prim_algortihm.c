/*
Authors:

    Orlando Mota Pires https://github.com/orlandomotapires
    Pedro Menezes https://github.com/pedromenezes49
    Francielle Cardoso https://github.com/francicardoso

*/

#include "prim/prim.h"
#include <time.h>

int main() {
    FILE *file_a;
    Graph *graph_a;
    Graph *final_tree;

    file_a = fopen("./adj_a.txt", "rt");

    graph_a = initialize_graph();
    final_tree = initialize_graph();

    if (file_a == NULL) {
        printf("Problems opening the file\n");
        return 1;
    }

    memset(visited, 0, sizeof(visited));

    srand(time(NULL));
    
    read_file_create_graph(&graph_a, &final_tree, file_a);

    // Gere um número aleatório no intervalo de 1 a 4 para ser o no inicial
    int numero_aleatorio = (rand() % num_vertices) + 1;

    printf("Complete Graph: \n");
    print_complete_graph(graph_a);

    prim(graph_a, &final_tree, numero_aleatorio);

    fclose(file_a);

    return 0;
}