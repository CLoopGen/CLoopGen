#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int j;
extern int default_order[32];
extern int tmp_reorder[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int i = 0; i < num_ref_idx_lX_active; i++) {
        for (j = i; j < i + 1; j++) {
            default_order[j] = tmp_reorder[j];
        }
    }
}
