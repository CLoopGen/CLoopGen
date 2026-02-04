#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int i;
extern int default_order[32];
extern int re_order[32];
extern int no_reorder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (j = 0; j < num_ref_idx_lX_active; j++) {
        re_order[j] = default_order[j];
        if (re_order[j] != default_order[j]) {
            no_reorder = 0;
        }
    }
}
