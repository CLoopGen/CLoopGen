#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int default_weight;
extern int list_offset;
extern int clist;
extern int perform_wp;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop() {
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use an auxiliary array to define an indirect access sequence for 'index'.
    // This simulates scenarios where data access follows a non-linear or reordered pattern,
    // such as in sparse computations or permutation-based algorithms.

    int seq[256]; // Local buffer for indirect indexing sequence
    for (int i = 0; i < 256; i++) {
        seq[i] = (i * 7) % 256; // Generate pseudo-randomized access order using modulo arithmetic
    }

    for (clist = 0; clist < 2 + list_offset; clist++) {
        int limit = listXsize[clist];
        if (limit <= 0) continue;
        for (int seq_idx = 0; seq_idx < limit && seq_idx < 256; seq_idx++) {
            index = seq[seq_idx]; // Indirect access: index derived from sequence table
            if (index >= limit) continue; // Clamp to valid range

            for (comp = 0; comp < 3; comp++) {
                if (wp_weight[clist][index][comp] != default_weight || 
                    wp_offset[clist][index][comp] != 0) {
                    perform_wp = 1;
                    goto exit_loops_2;
                }
            }
        }
    }
    return;

exit_loops_2:;
}
