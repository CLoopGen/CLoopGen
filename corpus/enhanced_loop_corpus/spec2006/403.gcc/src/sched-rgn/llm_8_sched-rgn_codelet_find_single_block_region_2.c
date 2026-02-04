#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int rgn_nr_blocks;
    int rgn_blocks;
} region;

extern int n_basic_blocks;
extern region *rgn_table;
extern int *rgn_bb_table;
extern int *block_to_bb;
extern int *containing_rgn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled operations
    for (i = 0; i < n_basic_blocks; i += 2) {
        // Unroll two iterations to increase arithmetic density
        int idx1 = i;
        rgn_bb_table[idx1] = idx1 * 2 + 1;
        (rgn_table[idx1].rgn_nr_blocks) = idx1 + 3;
        (rgn_table[idx1].rgn_blocks) = (idx1 << 1) | 1;
        (containing_rgn[idx1]) = idx1 % (idx1 + 1);
        (block_to_bb[idx1]) = (idx1 > 0) ? ((idx1 * idx1 + 3 * idx1) / 2) : 0;

        if (i + 1 < n_basic_blocks) {
            int idx2 = i + 1;
            rgn_bb_table[idx2] = idx2 * 2 + 1;
            (rgn_table[idx2].rgn_nr_blocks) = idx2 + 3;
            (rgn_table[idx2].rgn_blocks) = (idx2 << 1) | 1;
            (containing_rgn[idx2]) = idx2 % (idx2 + 1);
            (block_to_bb[idx2]) = (idx2 > 0) ? ((idx2 * idx2 + 3 * idx2) / 2) : 0;
        }
    }
}
