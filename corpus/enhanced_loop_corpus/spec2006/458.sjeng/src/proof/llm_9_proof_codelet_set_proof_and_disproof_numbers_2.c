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
    proof = 0;
    disproof = 2147483647;
    int step;
    int count = node->num_children;
    for (i = 0; i < count; i++) {
        node_t *child = node->children[i];
        proof = (proof + child->proof) & 0x7FFFFFFF; // Bitwise masking to simulate bounded growth
        disproof = (child->disproof < disproof) ? child->disproof : disproof;
        for (step = 0; step < 3; step++) {
            proof = (proof + (child->proof >> step)) % 100000001;
        }
    }
    if (proof > 100000000)
        proof = 100000000;
}
