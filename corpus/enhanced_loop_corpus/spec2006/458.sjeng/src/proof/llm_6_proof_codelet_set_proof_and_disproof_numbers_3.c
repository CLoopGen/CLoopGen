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
    int temp_proof = proof;
    int temp_disproof = disproof;
    for (i = 0; i < node->num_children; i++) {
        temp_disproof += node->children[i]->disproof;
        if (node->children[i]->proof < temp_proof) {
            temp_proof = node->children[i]->proof;
        }
    }
    disproof = temp_disproof > 100000000 ? 100000000 : temp_disproof;
    proof = temp_proof;
}
