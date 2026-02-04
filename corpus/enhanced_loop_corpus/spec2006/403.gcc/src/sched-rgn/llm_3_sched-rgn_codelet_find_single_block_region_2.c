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
    // Variant 2: Strided memory access - process every 2nd element forward, then fill in the gaps
    // This creates a strided access pattern on all arrays with stride 2
    int stride = 2;
    // First pass: even indices
    for (i = 0; i < n_basic_blocks; i += stride) {
        rgn_bb_table[i] = i;
        rgn_table[i].rgn_nr_blocks = 1;
        rgn_table[i].rgn_blocks = i;
        containing_rgn[i] = i;
        block_to_bb[i] = 0;
    }
    // Second pass: odd indices (strided continuation)
    for (i = 1; i < n_basic_blocks; i += stride) {
        rgn_bb_table[i] = i;
        rgn_table[i].rgn_nr_blocks = 1;
        rgn_table[i].rgn_blocks = i;
        containing_rgn[i] = i;
        block_to_bb[i] = 0;
    }
}
