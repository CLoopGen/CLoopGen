#include <stdio.h>

#include <inttypes.h>

extern unsigned int num_ref_idx_lX_active;
extern unsigned int i;
extern int default_order[32];
extern int re_order[32];
extern int no_reorder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (num_ref_idx_lX_active > 0) {
        i = 0;
        for (unsigned int outer = 0; outer < 1; outer++) {
            for (; i < num_ref_idx_lX_active; i++) {
                if (default_order[i] != re_order[i]) {
                    no_reorder = 0;
                }
            }
        }
    }
}
