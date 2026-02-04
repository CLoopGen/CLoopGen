#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int i;
extern int default_order[32];
extern int re_order[32];
extern int no_reorder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int k;
    int temp_no_reorder = 1;
    for (k = 0; k < num_ref_idx_lX_active; k++) {
        if (default_order[k] != re_order[k] && temp_no_reorder) {
            temp_no_reorder = 0;
        }
    }
    if (temp_no_reorder == 0) {
        no_reorder = 0;
    }
}
