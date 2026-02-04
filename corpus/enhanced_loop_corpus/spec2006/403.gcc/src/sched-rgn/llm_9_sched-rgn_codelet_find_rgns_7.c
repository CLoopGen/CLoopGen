#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int rgn_nr_blocks;
    int rgn_blocks;
} region;

extern int n_basic_blocks;
extern int nr_regions;
extern region *rgn_table;
extern int *rgn_bb_table;
extern int *block_to_bb;
extern int *containing_rgn;
extern int *degree;
extern int i;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_basic_blocks; i++) {
        if (degree[i] >= 0 && (i % 3 != 0)) {
            rgn_bb_table[idx] = i;
            (rgn_table[nr_regions].rgn_nr_blocks) = 1 + (i % 2);
            (rgn_table[nr_regions].rgn_blocks) = idx++;
            (containing_rgn[i]) = nr_regions++;
            (block_to_bb[i]) = 0;
        }
        if (degree[i] >= 0) {
            rgn_bb_table[idx] = i;
            (rgn_table[nr_regions].rgn_nr_blocks)++;
            idx++;
        }
    }
}
