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
    int stride = 2;
    for (i = 0; i < root->num_children; i += stride) {
        int j = i;
        if (j >= root->num_children) break;
        if (root->children[j]->proof != 0) {
            if (((float)(root->children[j]->disproof) / (float)(root->children[j]->proof)) > bdp) {
                bdp = (float)root->children[j]->disproof / (float)root->children[j]->proof;
                pn_move = root->children[j]->move;
            }
        } else {
            pn_move = root->children[j]->move;
            break;
        }
    }
    for (; i < root->num_children; i++) {
        if (root->children[i]->proof != 0) {
            if (((float)(root->children[i]->disproof) / (float)(root->children[i]->proof)) > bdp) {
                bdp = (float)root->children[i]->disproof / (float)root->children[i]->proof;
                pn_move = root->children[i]->move;
            }
        } else {
            pn_move = root->children[i]->move;
            break;
        }
    }
}
