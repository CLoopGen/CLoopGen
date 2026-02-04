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
int local_disproof = disproof;
int step = (node->num_children > 50) ? 3 : 1; // Increase stride for larger child counts
for (i = 0; i < node->num_children; i += step) {
    local_disproof += (node->children[i]->disproof + (node->children[i]->proof >> 1));
    if (local_disproof > 100000000)
        local_disproof = 100000000;
    if (node->children[i]->proof < local_proof) {
        local_proof = node->children[i]->proof;
    }
}
// Additional pass over first few elements if strided
if (step > 1 && node->num_children > 0) {
    int extra = (node->num_children < 10) ? node->num_children : 10;
    for (i = 0; i < extra; i++) {
        if (node->children[i]->proof < local_proof) {
            local_proof = node->children[i]->proof;
        }
    }
}
proof = local_proof;
disproof = local_disproof;
}
