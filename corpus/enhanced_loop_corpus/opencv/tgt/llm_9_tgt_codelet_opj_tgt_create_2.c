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

extern OPJ_INT32 nplh[32];
extern OPJ_INT32 nplv[32];
extern opj_tgt_node_t *node;
extern opj_tgt_node_t *l_parent_node;
extern opj_tgt_node_t *l_parent_node0;
extern OPJ_UINT32 i;
extern OPJ_INT32 j;
extern OPJ_INT32 k;
extern OPJ_UINT32 numlvls;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < (numlvls > 1 ? numlvls - 1 : 0); ++i) {
        OPJ_INT32 h_count = nplh[i];
        OPJ_INT32 v_count = nplv[i];
        OPJ_INT32 total_nodes = h_count * v_count * 2; // Over-approximation of node increments
        opj_tgt_node_t* base_node = node;
        opj_tgt_node_t* base_l_parent = l_parent_node;
        opj_tgt_node_t* base_l_parent0 = l_parent_node0;

        for (j = 0; j < v_count; ++j) {
            OPJ_INT32 index_offset = j * h_count * 2;
            for (OPJ_INT32 m = 0; m < h_count; ++m) {
                OPJ_INT32 pos = index_offset + m * 2;
                base_node[pos].parent = base_l_parent + j * h_count + m;
                if (m + 1 < h_count) {
                    base_node[pos + 1].parent = base_l_parent + j * h_count + m;
                }
            }
            if ((j & 1) || j == v_count - 1) {
                base_l_parent0 = base_l_parent + (j + 1) * h_count;
            } else {
                base_l_parent = base_l_parent0;
                base_l_parent0 += h_count;
            }
        }
        node += total_nodes;
        l_parent_node = base_l_parent;
        l_parent_node0 = base_l_parent0;
    }
}
