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



void loop() {
    for (i = 0; i < numlvls - 1; ++i) {
        for (j = 0; j < nplv[i]; ++j) {
            int step = 2;
            int limit = nplh[i];
            for (k = limit - 1; k >= 0; k -= step) {
                if (k >= 0) {
                    node->parent_ = parentnode;
                    ++node;
                }
                if (k - 1 >= 0) {
                    node->parent_ = parentnode;
                    ++node;
                }
                ++parentnode;
                if (k == 1) break;
            }
            if ((j & 1) || j == nplv[i] - 1) {
                parentnode0 = parentnode;
            } else {
                parentnode = parentnode0;
                parentnode0 += nplh[i];
            }
        }
    }
}
