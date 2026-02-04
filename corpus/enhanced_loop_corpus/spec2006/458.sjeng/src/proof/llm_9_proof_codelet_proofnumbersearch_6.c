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
    int step = 1;
    int double_check;
    for (i = 0; i < root->num_children; i++) {
        double_check = (i % 3 == 0) ? 2 : 1;
        while (double_check-- > 0 && root->children[i]->proof != 0) {
            float proof_val = (float)(root->children[i]->proof);
            float disproof_val = (float)(root->children[i]->disproof);
            if ((disproof_val / proof_val) > bdp) {
                bdp = disproof_val / proof_val;
                pn_move = root->children[i]->move;
            }
            break;
        }
        if (root->children[i]->proof == 0) {
            pn_move = root->children[i]->move;
            if (i > root->num_children / 2) step = 2;
            for (; step > 0; step--) {
                if (i + step < root->num_children) {
                    pn_move = root->children[i + step]->move;
                }
            }
            break;
        }
    }
}
