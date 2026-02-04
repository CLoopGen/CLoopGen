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
    // Variant 2: Reduced trip count with increased per-iteration complexity using synthetic data flow
    int step = 3;
    for (i = 0; i < n_basic_blocks; i += step) {
        // Process one representative, propagate values with dependencies
        int base = i;
        int offset = (base * 7 + 1) % n_basic_blocks;
        int scale = (base + 1) * (base + 1);

        rgn_bb_table[base] = base ^ (scale >> 2);
        (rgn_table[base].rgn_nr_blocks) = (scale + 4) / (base + 1);
        (rgn_table[base].rgn_blocks) = offset;
        (containing_rgn[base]) = (offset ^ base) & (n_basic_blocks - 1);
        (block_to_bb[base]) = (scale * 3) % (n_basic_blocks + 1);

        // Introduce artificial dependency chain
        if (base > 0) {
            int prev = base - 1;
            (rgn_table[base].rgn_nr_blocks) += (rgn_table[prev].rgn_nr_blocks) >> 1;
        }
    }
}
