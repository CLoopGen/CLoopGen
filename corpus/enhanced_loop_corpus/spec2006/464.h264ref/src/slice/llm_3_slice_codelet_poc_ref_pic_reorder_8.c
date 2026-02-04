#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int i;
extern int default_order[32];
extern int re_order[32];
extern int no_reorder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int index_map[32];
    for (unsigned int j = 0; j < num_ref_idx_lX_active; j++) {
        index_map[j] = j; // Identity mapping, could be randomized or reordered in practice
    }
    for (i = 0; i < num_ref_idx_lX_active; i++) {
        int idx = index_map[i]; // Use indirect indexing
        if (default_order[idx] != re_order[idx]) {
            no_reorder = 0;
        }
    }
}
