#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

typedef struct opj_tgt_node {
    struct opj_tgt_node *parent;
    OPJ_INT32 value;
    OPJ_INT32 low;
    OPJ_UINT32 known;
} opj_tgt_node_t;

typedef struct opj_tgt_tree {
    OPJ_UINT32 numleafsh;
    OPJ_UINT32 numleafsv;
    OPJ_UINT32 numnodes;
    opj_tgt_node_t *nodes;
    OPJ_UINT32 nodes_size;
} opj_tgt_tree_t;

opj_tgt_tree_t *p_tree;
OPJ_UINT32 i;
opj_tgt_node_t *l_current_node;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    const OPJ_UINT32 num_nodes = data_size / sizeof(opj_tgt_node_t);
    opj_tgt_node_t *nodes_buffer = (opj_tgt_node_t*)calloc(num_nodes, sizeof(opj_tgt_node_t));
    if (!nodes_buffer) exit(1);

    p_tree = (opj_tgt_tree_t*)malloc(sizeof(opj_tgt_tree_t));
    if (!p_tree) exit(1);

    p_tree->numleafsh = 0;
    p_tree->numleafsv = 0;
    p_tree->numnodes = num_nodes;
    p_tree->nodes = nodes_buffer;
    p_tree->nodes_size = num_nodes;

    l_current_node = p_tree->nodes;

    for (OPJ_UINT32 idx = 0; idx < num_nodes; ++idx) {
        nodes_buffer[idx].parent = (idx == 0) ? NULL : &nodes_buffer[idx - 1];
        nodes_buffer[idx].value = 0;
        nodes_buffer[idx].low = 0;
        nodes_buffer[idx].known = 0;
    }
}