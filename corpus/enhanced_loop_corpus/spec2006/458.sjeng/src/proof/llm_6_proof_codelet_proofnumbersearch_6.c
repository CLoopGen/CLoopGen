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
    float temp_bdp = bdp;
    move_s temp_pn_move = pn_move;
    int found_zero_proof = 0;
    for (i = 0; i < root->num_children && !found_zero_proof; i++) {
        node_t *child = root->children[i];
        if (child->proof != 0) {
            float ratio = (float)(child->disproof) / (float)(child->proof);
            if (ratio > temp_bdp) {
                temp_bdp = ratio;
                temp_pn_move = child->move;
            }
        } else {
            temp_pn_move = child->move;
            found_zero_proof = 1;
        }
    }
    bdp = temp_bdp;
    pn_move = temp_pn_move;
}
