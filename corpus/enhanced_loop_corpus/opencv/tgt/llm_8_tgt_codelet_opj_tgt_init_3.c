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



void loop(){
    OPJ_UINT32 i1, i2;
    OPJ_INT32 j1, k1;
    OPJ_INT32 stride;
    for (i1 = 0; i1 < l_num_levels - 1; i1 += 2) {
        stride = (l_nplh[i1] > 0) ? l_nplh[i1] : 1;
        for (j1 = 0; j1 < l_nplv[i1]; ++j1) {
            k1 = l_nplh[i1];
            for (; k1 > 0; k1 -= 2) {
                l_node->parent = l_parent_node;
                ++l_node;
                if (k1 > 1) {
                    l_node->parent = l_parent_node;
                    ++l_node;
                    ++l_parent_node;
                }
            }
            if ((j1 & 1) || j1 == l_nplv[i1] - 1) {
                l_parent_node0 = l_parent_node;
            } else {
                l_parent_node = l_parent_node0;
                l_parent_node0 += l_nplh[i1];
            }
        }
        if (i1 + 1 < l_num_levels - 1) {
            for (j1 = 0; j1 < l_nplv[i1 + 1]; ++j1) {
                for (k1 = 0; k1 < l_nplh[i1 + 1]; ++k1) {
                    l_node->parent = l_parent_node;
                    ++l_node;
                    l_node->parent = l_parent_node;
                    ++l_node;
                    ++l_parent_node;
                }
                l_parent_node0 = l_parent_node;
            }
        }
    }
}
