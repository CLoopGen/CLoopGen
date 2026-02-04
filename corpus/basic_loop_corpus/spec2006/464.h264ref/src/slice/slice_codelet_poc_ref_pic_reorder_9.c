#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int j;
extern int default_order[32];
extern int tmp_reorder[32];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < num_ref_idx_lX_active; j++) {
    default_order[j] = tmp_reorder[j];
}

}
