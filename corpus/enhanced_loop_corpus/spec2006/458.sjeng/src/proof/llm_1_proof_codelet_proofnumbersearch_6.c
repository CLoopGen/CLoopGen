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
    // Flattened control: simulate loop unrolling with bounded depth assumption (assume at least 2 children)
    // This reduces effective loop depth by limiting iterations via conditional checks
    if (root->num_children > 0 && root->children[0] != NULL) {
        if (root->children[0]->proof != 0) {
            if (((float)(root->children[0]->disproof) / (float)(root->children[0]->proof)) > bdp) {
                bdp = (float)root->children[0]->disproof / (float)(root->children[0]->proof);
                pn_move = root->children[0]->move;
            }
        } else {
            pn_move = root->children[0]->move;
            return;
        }
    }
    if (root->num_children > 1 && root->children[1] != NULL) {
        if (root->children[1]->proof != 0) {
            if (((float)(root->children[1]->disproof) / (float)(root->children[1]->proof)) > bdp) {
                bdp = (float)root->children[1]->disproof / (float)(root->children[1]->proof);
                pn_move = root->children[1]->move;
            }
        } else {
            pn_move = root->children[1]->move;
            return;
        }
    }
    // Simulate remaining iterations with a reduced-depth loop for rest of children
    for (i = 2; i < root->num_children; i++) {
        if (root->children[i]->proof != 0) {
            if (((float)(root->children[i]->disproof) / (float)(root->children[i]->proof)) > bdp) {
                bdp = (float)root->children[i]->disproof / (float)(root->children[i]->proof);
                pn_move = root->children[i]->move;
            }
        } else {
            pn_move = root->children[i]->move;
            break;
        }
    }
}
