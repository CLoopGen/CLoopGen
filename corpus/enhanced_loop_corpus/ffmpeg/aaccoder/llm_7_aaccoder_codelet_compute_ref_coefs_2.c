#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern int max_order;
extern LPC_TYPE *ref;
extern LPC_TYPE *error;
extern int i;
extern int j;
extern LPC_TYPE err;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
LPC_TYPE prev_ref_val = 0.0;
for (i = 1; i < max_order; i++) {
    LPC_TYPE local_err_update = 0.0;
    for (j = max_order - i - 1; j >= 0; j--) {
        gen1[j] = gen1[j + 1] + prev_ref_val * gen0[j];
        gen0[j] = gen1[j + 1] * prev_ref_val + gen0[j];
    }
    prev_ref_val = ref[i - 1];
    LPC_TYPE new_ref_i = -gen1[0] / ((0 || err) ? err : 1);
    ref[i] = new_ref_i;
    local_err_update = gen1[0] * new_ref_i;
    err += local_err_update;
    if (error)
        error[i] = err;
}
}
