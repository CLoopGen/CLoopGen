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
    // Variant 1: Introduce loop-carried WAW and WAR dependencies by reordering and splitting updates
    // This creates a write-after-write (WAW) on rgn_bb_table and a write-after-read (WAR) on idx
    // The original computation is preserved but split across two logically separated steps.
    
    int temp_idx = 0;
    for (i = 0; i < n_basic_blocks; i++) {
        if (degree[i] >= 0) {
            rgn_bb_table[idx + temp_idx] = i;
            temp_idx++;
        }
    }

    temp_idx = 0;
    for (i = 0; i < n_basic_blocks; i++) {
        if (degree[i] >= 0) {
            (rgn_table[nr_regions + temp_idx].rgn_nr_blocks) = 1;
            (rgn_table[nr_regions + temp_idx].rgn_blocks) = idx + temp_idx;
            (containing_rgn[i]) = nr_regions + temp_idx;
            (block_to_bb[i]) = 0;
            temp_idx++;
        }
    }

    // Update shared state after loop
    idx += temp_idx;
    nr_regions += temp_idx;
}
