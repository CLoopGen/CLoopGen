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

extern OPJ_INT32 l_nplh[32];
extern OPJ_INT32 l_nplv[32];
extern opj_tgt_node_t *l_node;
extern opj_tgt_node_t *l_parent_node;
extern opj_tgt_node_t *l_parent_node0;
extern OPJ_UINT32 i;
extern OPJ_INT32 j;
extern OPJ_INT32 k;
extern OPJ_UINT32 l_num_levels;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    OPJ_UINT32 node_offset = 0;
    OPJ_UINT32 parent_offset = 0;
    for (i = 0; i < l_num_levels - 1; ++i) {
        OPJ_INT32 h = l_nplh[i];
        OPJ_INT32 v = l_nplv[i];
        for (j = 0; j < v; ++j) {
            for (OPJ_INT32 k_idx = h - 1; k_idx >= 0; --k_idx) {
                OPJ_UINT32 current_parent_idx = parent_offset + (h - 1 - k_idx);
                l_node[node_offset].parent = &l_parent_node[current_parent_idx];
                node_offset++;
                if (k_idx > 0) {
                    l_node[node_offset].parent = &l_parent_node[current_parent_idx];
                    node_offset++;
                }
            }
            parent_offset += h;
            if ((j & 1) || j == v - 1) {
                l_parent_node0 = &l_parent_node[parent_offset - h];
            } else {
                l_parent_node = l_parent_node0;
                l_parent_node0 += h;
            }
        }
    }
}
