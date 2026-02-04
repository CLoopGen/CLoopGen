#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

static node_t **children_array = NULL;
static node_t *nodes = NULL;
static int total_nodes = 0;

node_t *node;
int proof;
int disproof;
int i;

void init_vars() {
    const int data_size = 16 * 1024 * 1024; // Aim for ~16MB of node data
    total_nodes = data_size / (sizeof(node_t) + sizeof(node_t*));
    if (total_nodes < 2) total_nodes = 2;
    
    // Allocate pool of nodes
    nodes = calloc(total_nodes, sizeof(node_t));
    if (!nodes) exit(1);
    
    // Allocate children array for the root's children
    children_array = malloc(total_nodes * sizeof(node_t*));
    if (!children_array) exit(1);
    
    // Initialize all child nodes
    for (int j = 1; j < total_nodes; j++) {
        nodes[j].value = j & 0xFF;
        nodes[j].num_children = 0;
        nodes[j].expanded = 1;
        nodes[j].evaluated = 1;
        nodes[j].proof = 50 + (j % 100);
        nodes[j].disproof = 40 + (j % 100);
        nodes[j].children = NULL;
        nodes[j].parent = &nodes[0];
        nodes[j].move.from = j - 1;
        nodes[j].move.target = j;
        nodes[j].move.captured = 0;
        nodes[j].move.promoted = 0;
        nodes[j].move.castled = 0;
        nodes[j].move.ep = 0;
        
        children_array[j-1] = &nodes[j];
    }
    
    // Setup root node (node)
    node = &nodes[0];
    node->value = 0;
    node->num_children = total_nodes - 1;
    node->expanded = 1;
    node->evaluated = 1;
    node->proof = 200;
    node->disproof = 150;
    node->children = children_array;
    node->parent = NULL;
    memset(&node->move, 0, sizeof(move_s));
    
    // Initialize loop variables
    proof = 100000001;
    disproof = 0;
    i = 0;
}

// Ensure initialization happens before any call to loop
__attribute__((constructor)) void initialize() {
    init_vars();
}