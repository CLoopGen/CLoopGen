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

extern move_s pn_move;
extern node_t *root;
extern int i;
extern float bdp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[256];
    int count = root->num_children > 256 ? 256 : root->num_children;
    for (i = 0; i < count; i++) {
        indices[i] = i;
    }
    for (i = 0; i < count; i++) {
        int idx = indices[i];
        if (root->children[idx]->proof != 0) {
            if (((float)(root->children[idx]->disproof) / (float)(root->children[idx]->proof)) > bdp) {
                bdp = (float)root->children[idx]->disproof / (float)root->children[idx]->proof;
                pn_move = root->children[idx]->move;
            }
        } else {
            pn_move = root->children[idx]->move;
            break;
        }
    }
}
