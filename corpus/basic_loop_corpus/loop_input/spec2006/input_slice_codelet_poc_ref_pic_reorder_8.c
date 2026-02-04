#include <stdint.h>

unsigned int num_ref_idx_lX_active = 32;
unsigned int i = 0;
int default_order[32] = {0};
int re_order[32] = {0};
int no_reorder = 1;

void init_vars() {
    num_ref_idx_lX_active = 32;
    no_reorder = 1;
    for (i = 0; i < num_ref_idx_lX_active; i++) {
        default_order[i] = i;
        re_order[i] = i;
    }
    re_order[16] = 0;
}