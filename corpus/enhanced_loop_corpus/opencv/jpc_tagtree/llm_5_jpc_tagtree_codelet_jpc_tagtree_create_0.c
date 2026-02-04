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
    for (j = 0; j < nplv[i]; ++j) {
        int count = nplh[i];
        int writes = 0;
        while (writes < count) {
            node->parent_ = parentnode;
            ++node;
            ++writes;
            if (writes < count) {
                node->parent_ = parentnode;
                ++node;
                ++writes;
            }
            ++parentnode;
        }
        parentnode = (j & 1) ? parentnode : ((j == nplv[i] - 1) ? parentnode : parentnode0);
        if (!(j & 1) && j != nplv[i] - 1) {
            parentnode0 += nplh[i];
        }
    }
}
}
