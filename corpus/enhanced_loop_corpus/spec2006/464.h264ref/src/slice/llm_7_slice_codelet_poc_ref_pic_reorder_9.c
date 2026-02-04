#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int j;
extern int default_order[32];
extern int tmp_reorder[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    for (i = 0; i < num_ref_idx_lX_active; i++) {
        default_order[i] = tmp_reorder[i];
        default_order[i] = default_order[i]; // Introduce WAW (write-after-write) and reuse same location immediately (redundant write)
    }
}
