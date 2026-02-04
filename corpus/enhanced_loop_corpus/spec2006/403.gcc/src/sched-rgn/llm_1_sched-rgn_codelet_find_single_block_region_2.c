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
for (i = 0; i < n_basic_blocks; i += 2) {
    if (i < n_basic_blocks) {
        rgn_bb_table[i] = i;
        (rgn_table[i].rgn_nr_blocks) = 1;
        (rgn_table[i].rgn_blocks) = i;
        (containing_rgn[i]) = i;
        (block_to_bb[i]) = 0;
    }
    if (i + 1 < n_basic_blocks) {
        rgn_bb_table[i + 1] = i + 1;
        (rgn_table[i + 1].rgn_nr_blocks) = 1;
        (rgn_table[i + 1].rgn_blocks) = i + 1;
        (containing_rgn[i + 1]) = i + 1;
        (block_to_bb[i + 1]) = 0;
    }
}
}
