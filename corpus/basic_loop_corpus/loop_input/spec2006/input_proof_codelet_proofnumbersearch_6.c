#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

move_s pn_move;
node_t *root;
int i;
float bdp;

#define NUM_CHILDREN 100000

static node_t** children_array;
static node_t* nodes_memory;

void init_vars() {
    children_array = (node_t**)calloc(NUM_CHILDREN, sizeof(node_t*));
    nodes_memory = (node_t*)calloc(NUM_CHILDREN + 1, sizeof(node_t));

    for (int idx = 0; idx < NUM_CHILDREN; idx++) {
        node_t* node = &nodes_memory[idx];
        node->value = 1;
        node->num_children = 0;
        node->expanded = 1;
        node->evaluated = 1;
        node->proof = (idx % 2) ? (idx / 1000 + 1) : 0;
        node->disproof = idx / 500 + 1;
        node->children = NULL;
        node->parent = &nodes_memory[NUM_CHILDREN];
        node->move.from = idx;
        node->move.target = idx + 10;
        node->move.captured = 0;
        node->move.promoted = 0;
        node->move.castled = 0;
        node->move.ep = 0;

        children_array[idx] = node;
    }

    root = &nodes_memory[NUM_CHILDREN];
    root->value = 0;
    root->num_children = NUM_CHILDREN;
    root->expanded = 1;
    root->evaluated = 1;
    root->proof = 1;
    root->disproof = 1;
    root->children = children_array;
    root->parent = NULL;
    root->move.from = -1;
    root->move.target = -1;
    root->move.captured = -1;
    root->move.promoted = -1;
    root->move.castled = -1;
    root->move.ep = -1;

    pn_move.from = 0;
    pn_move.target = 0;
    pn_move.captured = 0;
    pn_move.promoted = 0;
    pn_move.castled = 0;
    pn_move.ep = 0;

    bdp = 0.0f;
    i = 0;
}