#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

typedef struct node {
    unsigned char value;
    unsigned char num_children;
    unsigned char expanded;
    unsigned char evaluated;
    int proof;
    int disproof;
    struct node **children;
    struct node *parent;
    move_s move;
} node_t;

node_t **global_children_pool = NULL;
node_t *node_array = NULL;
int proof = 0;
int disproof = 100000000;
int i = 0;
node_t *node = NULL;

void init_vars() {
    const int total_nodes = 20000; 
    global_children_pool = (node_t**)calloc(total_nodes, sizeof(node_t*));
    node_array = (node_t*)calloc(total_nodes, sizeof(node_t));

    for (int idx = 0; idx < total_nodes; ++idx) {
        node_array[idx].value = idx % 256;
        node_array[idx].num_children = 0;
        node_array[idx].expanded = 1;
        node_array[idx].evaluated = 1;
        node_array[idx].proof = (idx % 20000000) + 1;
        node_array[idx].disproof = (idx % 20000000) + 1;
        node_array[idx].parent = (idx > 0) ? &node_array[idx/2] : NULL;
        node_array[idx].move.from = idx * 3;
        node_array[idx].move.target = idx * 7;
        node_array[idx].move.captured = 0;
        node_array[idx].move.promoted = 0;
        node_array[idx].move.castled = 0;
        node_array[idx].move.ep = 0;
        global_children_pool[idx] = &node_array[idx];
    }

    node = &node_array[0];
    node->num_children = 15000;
    node->children = (node_t**)malloc(node->num_children * sizeof(node_t*));
    for (int j = 0; j < node->num_children; ++j) {
        node->children[j] = global_children_pool[j];
    }

    proof = 0;
    disproof = 100000000;
}