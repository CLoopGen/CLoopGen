#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

typedef struct opj_tgt_node {
    struct opj_tgt_node *parent;
    OPJ_INT32 value;
    OPJ_INT32 low;
    OPJ_UINT32 known;
} opj_tgt_node_t;

OPJ_INT32 nplh[32];
OPJ_INT32 nplv[32];
opj_tgt_node_t *node;
opj_tgt_node_t *l_parent_node;
opj_tgt_node_t *l_parent_node0;
OPJ_UINT32 i;
OPJ_INT32 j;
OPJ_INT32 k;
OPJ_UINT32 numlvls;

#define DATA_SIZE (64 * 1024 * 1024)
static opj_tgt_node_t nodes_pool[DATA_SIZE / sizeof(opj_tgt_node_t)];
static opj_tgt_node_t parent_nodes_pool[8192];

void init_vars() {
    numlvls = 10;
    
    for (OPJ_UINT32 idx = 0; idx < numlvls; ++idx) {
        nplh[idx] = 128 >> (idx / 2);
        nplv[idx] = 64 >> (idx / 2);
        if (nplh[idx] == 0) nplh[idx] = 1;
        if (nplv[idx] == 0) nplv[idx] = 1;
    }
    
    node = nodes_pool;
    l_parent_node = parent_nodes_pool;
    l_parent_node0 = parent_nodes_pool;
}