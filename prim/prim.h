#include "graph.h"
#include "stack.h"

int num_vertices = 0;

typedef struct{
    int letter;
    int weight;
}tp_node;

int adjacency_matrix_a[50][50];
int visited[500];
tp_node open_nodes[500];
int last_pos = 0;

void pedro_bubble(){
    for(int i = 0; i < last_pos; i++){
        for(int j = 0; j < last_pos; j++){
            if(open_nodes[i].weight < open_nodes[j].weight){
                int aux_letter = open_nodes[i].letter;
                int aux_weight = open_nodes[i].weight;

                open_nodes[i].letter = open_nodes[j].letter;
                open_nodes[i].weight = open_nodes[j].weight;

                open_nodes[j].letter = aux_letter;
                open_nodes[j].weight = aux_weight;
                
            }
        }
    }
}

void read_file_create_graph(Graph **graph, FILE *file) {
    int a, i = 0;
    char Line[300];

    Graph *node_to_insert, *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    if (fgets(Line, 100, file)) {
        for (a = 0; a < (strlen(Line)); a++) {
            if (Line[a] != ' '){
                insert_main_list(graph, Line[a]);
                if(Line[a] >= 65) num_vertices++;
            }   
        }
    }

    int weight;
    while (!feof(file) && i < num_vertices) {
        for (a = 0; a < num_vertices; a++) {
            fscanf(file, "%d", &weight);

            if(weight > 0){
                node_to_insert = find_vertex(*graph, a + 1);
                base_node = find_vertex(*graph, (i + 1));

                insert_at_end_adj_list(&node_to_insert->main_list, &base_node, weight);
            }
        }
        i++;
    }
}

void insert_neighbors_on_list(Node *current){
    while (current != NULL) {
        if(visited[current->pointed_letter->letter] == 0){
            open_nodes[last_pos].letter = current->pointed_letter->letter;
            open_nodes[last_pos].weight = current->weight;
            last_pos++;
        }
           
        if (current->adjacency_list == NULL) {
            printf(" %c|%d \n", current->pointed_letter->letter, current->weight);
            current = current->adjacency_list;
        } else {
            printf(" %c|%d ->", current->pointed_letter->letter, current->weight);
            current = current->adjacency_list;
        }

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

void print_open_nodes(){
    for(int i = 0; i < last_pos; i++){
        printf("%c|%d ", open_nodes[i].letter, open_nodes[i].weight);
    }
    printf("\n");
}

int not_all_visited(){
    for(int i = 65; i < 65 + num_vertices; i++){
        if(visited[i] == 0) return 1;
    }

    return 0;
}

void prim(Graph *graph, int num_vertex){
    Graph *start_node;

    while(not_all_visited()){
        start_node = initialize_graph();
        start_node = find_vertex(graph, num_vertex);

        visited[start_node->letter] = 1;

        for(int k = 0, h = 0; k < last_pos; k++){
            if(visited[open_nodes[k].letter] != 1){
                open_nodes[h] = open_nodes[k];
                h++;
            }
        }

        print_open_nodes();

        insert_neighbors_on_list(start_node->main_list->adjacency_list);
        
        printf("BEFORE: \n");
        print_open_nodes();

        pedro_bubble();
        printf("AFTER: \n");
        print_open_nodes();

        num_vertex = open_nodes[0].letter;
    }

}
