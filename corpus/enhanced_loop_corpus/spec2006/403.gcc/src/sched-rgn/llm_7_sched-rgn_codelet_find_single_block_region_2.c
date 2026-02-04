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
    for (i = 1; i < n_basic_blocks; i++) {
        rgn_bb_table[i] = rgn_bb_table[i-1] + 1;
        (rgn_table[i].rgn_nr_blocks) = (rgn_table[i-1].rgn_nr_blocks) + 1;
        (rgn_table[i].rgn_blocks) = i;
        (containing_rgn[i]) = (containing_rgn[i-1]);
        (block_to_bb[i]) = 0;
    }
    if (n_basic_blocks > 0) {
        rgn_bb_table[0] = 0;
        (rgn_table[0].rgn_nr_blocks) = 1;
        (rgn_table[0].rgn_blocks) = 0;
        (containing_rgn[0]) = 0;
        (block_to_bb[0]) = 0;
    }
}
