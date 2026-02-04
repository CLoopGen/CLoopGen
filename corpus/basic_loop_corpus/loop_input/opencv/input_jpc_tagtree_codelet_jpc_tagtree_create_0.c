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

int nplh[32];
int nplv[32];
jpc_tagtreenode_t *node;
jpc_tagtreenode_t *parentnode;
jpc_tagtreenode_t *parentnode0;
int i;
int j;
int k;
int numlvls;

#define DATA_SIZE_MB 64
#define TOTAL_NODES ((DATA_SIZE_MB * (1 << 20)) / sizeof(jpc_tagtreenode_t))

static jpc_tagtreenode_t node_pool[TOTAL_NODES];
static jpc_tagtreenode_t parent_pool[TOTAL_NODES];

void init_vars() {
    numlvls = 32;
    for (int idx = 0; idx < 32; ++idx) {
        nplh[idx] = (idx + 1) * 3;
        nplv[idx] = (idx + 1) * 2;
    }

    node = node_pool;
    parentnode = parent_pool;
    parentnode0 = parent_pool;

    for (int idx = 0; idx < TOTAL_NODES; ++idx) {
        node_pool[idx].parent_ = NULL;
        node_pool[idx].value_ = idx;
        node_pool[idx].low_ = idx % 100;
        node_pool[idx].known_ = idx % 2;

        parent_pool[idx].parent_ = NULL;
        parent_pool[idx].value_ = -idx;
        parent_pool[idx].low_ = idx % 50;
        parent_pool[idx].known_ = (idx + 1) % 2;
    }
}