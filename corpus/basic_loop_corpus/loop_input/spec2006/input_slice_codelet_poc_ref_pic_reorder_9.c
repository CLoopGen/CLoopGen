#include <inttypes.h>

unsigned int num_ref_idx_lX_active = 32;
unsigned int j;
int default_order[32] = {0};
int tmp_reorder[32] = {0};

void init_vars() {
    num_ref_idx_lX_active = 32;
    for (unsigned int i = 0; i < 32; i++) {
        tmp_reorder[i] = i + 1;
        default_order[i] = 0;
    }
}