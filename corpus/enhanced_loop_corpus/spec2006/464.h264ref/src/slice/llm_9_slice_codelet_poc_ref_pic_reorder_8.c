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
    for (i = 0; i < num_ref_idx_lX_active; i++) {
        for (j = 0; j < 2; j++) {
            if ((default_order[i] ^ re_order[i]) & (1 << j)) {
                no_reorder = 0;
            }
        }
    }
}
