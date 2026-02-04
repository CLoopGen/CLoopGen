#include <stdio.h>

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

extern node_t *node;
extern int proof;
extern int disproof;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_proof = proof;
    int accumulated_disproof = 0;
    int j;
    // Introduce loop-carried dependence via sequential update with artificial dependency chain
    for (j = 0; j < node->num_children; j++) {
        accumulated_disproof = accumulated_disproof + node->children[j]->disproof;
        // Create WAW and RAW dependencies by reusing and updating same variable in sequence
        if (node->children[(j + 1) % node->num_children]->proof < local_proof) {
            local_proof = node->children[(j + 1) % node->num_children]->proof;
        }
    }
    disproof = accumulated_disproof > 100000000 ? 100000000 : accumulated_disproof;
    proof = local_proof;
}
