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
    int limit = root->num_children;
    float inv_proof;
    float ratio;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 >= limit) break;
        if (root->children[i]->proof != 0) {
            inv_proof = 1.0f / (float)(root->children[i]->proof);
            ratio = (float)(root->children[i]->disproof) * inv_proof;
            if (ratio > bdp) {
                bdp = ratio;
                pn_move = root->children[i]->move;
            }
        } else {
            pn_move = root->children[i]->move;
            break;
        }
        if (root->children[i+1]->proof != 0) {
            inv_proof = 1.0f / (float)(root->children[i+1]->proof);
            ratio = (float)(root->children[i+1]->disproof) * inv_proof;
            if (ratio > bdp) {
                bdp = ratio;
                pn_move = root->children[i+1]->move;
            }
        } else {
            pn_move = root->children[i+1]->move;
            break;
        }
    }
    if (limit % 2 == 1 && i == limit - 1) {
        if (root->children[i]->proof != 0) {
            ratio = (float)(root->children[i]->disproof) / (float)(root->children[i]->proof);
            if (ratio > bdp) {
                bdp = ratio;
                pn_move = root->children[i]->move;
            }
        } else {
            pn_move = root->children[i]->move;
        }
    }
}
