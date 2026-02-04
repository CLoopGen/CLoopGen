#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int i;
extern int default_order[32];
extern int re_order[32];
extern int no_reorder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_ref_idx_lX_active && i < 32; i += 2) {
        if (default_order[i] != re_order[i]) {
            no_reorder = 0;
        }
        if (i + 1 < num_ref_idx_lX_active && default_order[i + 1] == re_order[i + 1]) {
            no_reorder = no_reorder & 1;
        }
    }
}
