#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct jpc_tagtreenode_ {
    struct jpc_tagtreenode_ *parent_;
    int value_;
    int low_;
    int known_;
} jpc_tagtreenode_t;

extern int nplh[32];
extern int nplv[32];
extern jpc_tagtreenode_t *node;
extern jpc_tagtreenode_t *parentnode;
extern jpc_tagtreenode_t *parentnode0;
extern int i;
extern int j;
extern int k;
extern int numlvls;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < numlvls - 1; ++i) {
    jpc_tagtreenode_t* temp_node = node;
    jpc_tagtreenode_t* temp_parent = parentnode;
    jpc_tagtreenode_t* temp_parent0 = parentnode0;
    for (j = 0; j < nplv[i]; ++j) {
        int h_count = nplh[i];
        for (k = 0; k < h_count; ++k) {
            temp_node->parent_ = temp_parent;
            temp_node++;
            temp_parent++;
        }
        if ((j & 1) || j == nplv[i] - 1) {
            temp_parent0 = temp_parent;
        } else {
            temp_parent = temp_parent0;
            temp_parent0 += nplh[i];
        }
    }
    node = temp_node;
    parentnode = temp_parent;
    parentnode0 = temp_parent0;
}
}
