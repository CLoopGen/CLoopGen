#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int j;
extern int default_order[32];
extern int tmp_reorder[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j < num_ref_idx_lX_active; j++) {
        default_order[j] = tmp_reorder[j-1]; // Introduce RAW dependency: current iteration reads from previous iteration's source index
    }
    if (num_ref_idx_lX_active > 0) {
        default_order[0] = tmp_reorder[0];
    }
}
