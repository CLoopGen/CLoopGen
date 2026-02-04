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

extern opj_tgt_tree_t *p_tree;
extern OPJ_UINT32 i;
extern opj_tgt_node_t *l_current_node;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every 2nd node, then fill in the gaps)
    opj_tgt_node_t *nodes = p_tree->nodes;
    OPJ_UINT32 numnodes = p_tree->numnodes;

    // First pass: access nodes with stride 2 (even indices)
    for (i = 0; i < numnodes; i += 2) {
        l_current_node = &nodes[i];
        l_current_node->value = 999;
        l_current_node->low = 0;
        l_current_node->known = 0;
    }

    // Second pass: access remaining nodes (odd indices)
    for (i = 1; i < numnodes; i += 2) {
        l_current_node = &nodes[i];
        l_current_node->value = 999;
        l_current_node->low = 0;
        l_current_node->known = 0;
    }
}
