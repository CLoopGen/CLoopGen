#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int j;
extern int default_order[32];
extern int tmp_reorder[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < num_ref_idx_lX_active; j += 2) {
        default_order[j] = tmp_reorder[j];
        if (j + 1 < num_ref_idx_lX_active) {
            default_order[j + 1] = tmp_reorder[j + 1];
        }
    }
}
