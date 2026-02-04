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
for (i = 0; i < root->num_children; i++) {
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
