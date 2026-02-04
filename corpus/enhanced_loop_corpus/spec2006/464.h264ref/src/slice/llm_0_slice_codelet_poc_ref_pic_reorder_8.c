#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int i;
extern int default_order[32];
extern int re_order[32];
extern int no_reorder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < num_ref_idx_lX_active; j++) {
        for (i = 0; i <= j; i++) {
            if (default_order[i] != re_order[i]) {
                no_reorder = 0;
            }
        }
    }
}
