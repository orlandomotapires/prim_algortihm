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

void read_file_create_graph(Graph **graph, Graph **final_tree, FILE *file) {
    int a, i = 0;
    char Line[300];

    Graph *node_to_insert, *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    if (fgets(Line, 100, file)) {
        for (a = 0; a < (strlen(Line)); a++) {
            if (Line[a] != ' '){
                insert_main_list(graph, Line[a]);
                insert_main_list(final_tree, Line[a]);
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
            //printf("%c|%d \n", current->pointed_letter->letter, current->weight);
            current = current->adjacency_list;
        } else {
            //printf("%c|%d ->", current->pointed_letter->letter, current->weight);
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

void remove_if_visited(){
    for(int k = 0, h = 0; k < last_pos; k++){
        if(visited[open_nodes[k].letter] != 1){
            open_nodes[h] = open_nodes[k];
            h++;
        }
    }
}

int search_node_from(Graph *graph, tp_node node){
    Graph* current;
    Node* aux;

    int result = 1;

    current = graph;
    while (current->main_list->pointed_letter != NULL) {

        Node* current2;
        current2 = current->main_list->adjacency_list;

        while (current2 != NULL) {
            if(current2->pointed_letter->letter == node.letter && current2->weight == node.weight) return result;
            current2 = current2->adjacency_list;
        }

        current = current->main_list->pointed_letter;
        result++;
    }
}

void insert_node_in_tree(Graph **final_tree, Graph *graph, tp_node node){
    Graph *node_to_insert;
    Graph *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    int node_from = search_node_from(graph, node);

    node_to_insert = find_vertex(*final_tree, node.letter - 64);
    base_node = find_vertex(*final_tree, node_from);

    insert_at_end_adj_list(&node_to_insert->main_list, &base_node, node.weight);

    base_node = find_vertex(*final_tree, node.letter - 64);
    node_to_insert = find_vertex(*final_tree, node_from);

    insert_at_end_adj_list(&node_to_insert->main_list, &base_node, node.weight);
}

void prim(Graph *graph, Graph **final_tree, int num_vertex){
    Graph *current_node;

    printf("\nChoices: %c|%d ", num_vertex+64, 0);
    while(not_all_visited()){
        
        current_node = initialize_graph();     
        current_node = find_vertex(graph, num_vertex);

        if(visited[current_node->letter] == 0) insert_neighbors_on_list(current_node->main_list->adjacency_list);

        pedro_bubble();

        visited[current_node->letter] = 1;

        remove_if_visited();

        if(not_all_visited()) printf("-> %c|%d ", open_nodes[0].letter, open_nodes[0].weight);

        num_vertex = open_nodes[0].letter - 64;

        if(not_all_visited()) insert_node_in_tree(final_tree, graph, open_nodes[0]);
    }

    printf("\n\n");

    printf("Final tree: \n");
    print_complete_graph(*final_tree);

}
