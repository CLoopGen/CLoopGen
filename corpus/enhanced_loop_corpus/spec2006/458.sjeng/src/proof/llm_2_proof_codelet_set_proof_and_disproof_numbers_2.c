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
    int n = node->num_children;
    for (i = 0; i < n; i += 2) {
        proof += node->children[i]->proof;
        if (proof > 100000000)
            proof = 100000000;
        if (node->children[i]->disproof < disproof) {
            disproof = node->children[i]->disproof;
        }
    }
    // Handle odd-sized children array
    if (n % 2 == 1) {
        proof += node->children[n-1]->proof;
        if (proof > 100000000)
            proof = 100000000;
        if (node->children[n-1]->disproof < disproof) {
            disproof = node->children[n-1]->disproof;
        }
    }
}
