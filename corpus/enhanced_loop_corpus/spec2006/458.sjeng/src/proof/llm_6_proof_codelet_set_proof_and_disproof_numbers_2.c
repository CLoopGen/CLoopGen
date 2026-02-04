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
    int temp_proof = 0;
    int min_disproof = disproof;
    for (i = 0; i < node->num_children; i++) {
        temp_proof += node->children[i]->proof;
        if (node->children[i]->disproof < min_disproof) {
            min_disproof = node->children[i]->disproof;
        }
    }
    proof += temp_proof;
    if (proof > 100000000)
        proof = 100000000;
    disproof = min_disproof;
}
