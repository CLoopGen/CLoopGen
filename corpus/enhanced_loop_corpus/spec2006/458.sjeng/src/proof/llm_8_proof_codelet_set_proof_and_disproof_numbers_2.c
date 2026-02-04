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
    int limit = node->num_children;
    proof = 0; // Reset proof for accumulation
    disproof = 100000000; // Initialize disproof to a high value
    for (i = 0; i < limit; i += 2) {
        node_t *child1 = node->children[i];
        proof += child1->proof;
        if (node->children[i]->disproof < disproof) {
            disproof = node->children[i]->disproof;
        }
        if (i + 1 < limit) {
            node_t *child2 = node->children[i + 1];
            proof += child2->proof;
            if (child2->disproof < disproof) {
                disproof = child2->disproof;
            }
        }
    }
    if (proof > 100000000)
        proof = 100000000;
}
