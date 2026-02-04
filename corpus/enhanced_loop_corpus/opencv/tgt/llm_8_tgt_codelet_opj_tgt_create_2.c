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
    OPJ_UINT32 outer_limit = numlvls - 1;
    for (i = 0; i < outer_limit; ++i) {
        OPJ_INT32 vertical_count = nplv[i];
        OPJ_INT32 horizontal_count = nplh[i];
        for (j = 0; j < vertical_count; ++j) {
            OPJ_INT32 k = horizontal_count;
            for (; k > 0; --k) {
                node->parent = l_parent_node;
                ++node;
                if ((k -= 1) >= 0) {
                    node->parent = l_parent_node;
                    ++node;
                }
                ++l_parent_node;
            }
            if ((j & 1) || j == vertical_count - 1) {
                l_parent_node0 = l_parent_node;
            } else {
                l_parent_node = l_parent_node0;
                l_parent_node0 += horizontal_count;
            }
        }
    }
}
