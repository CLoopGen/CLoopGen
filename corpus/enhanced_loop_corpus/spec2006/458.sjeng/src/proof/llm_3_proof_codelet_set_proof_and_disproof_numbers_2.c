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
    struct node **child_list = node->children;
    int *proof_array = (int*)__builtin_alloca(node->num_children * sizeof(int));
    int *disproof_array = (int*)__builtin_alloca(node->num_children * sizeof(int));

    for (i = 0; i < node->num_children; i++) {
        proof_array[i] = child_list[i]->proof;
        disproof_array[i] = child_list[i]->disproof;
    }

    for (i = 0; i < node->num_children; i++) {
        proof += proof_array[i];
        if (proof > 100000000)
            proof = 100000000;
        if (disproof_array[i] < disproof) {
            disproof = disproof_array[i];
        }
    }
}
