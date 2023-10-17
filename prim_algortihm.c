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

    file_a = fopen("./adj_a.txt", "rt");

    graph_a = initialize_graph();

    if (file_a == NULL) {
        printf("Problems opening the file\n");
        return 1;
    }

    srand(time(NULL));
    
   
    
    // Imprima o número aleatório
    //printf("Número aleatório entre 65 e 68: %d\n", numero_aleatorio);

    read_file_create_graph(&graph_a, file_a);
    //print_matrix(adjacency_matrix_a);

     // Gere um número aleatório no intervalo de 65 a 68
    int numero_aleatorio = (rand() % num_vertices) + 65;

    print_complete_graph(graph_a);

    //prim(graph_a, numero_aleatorio);

    fclose(file_a);

    return 0;
}