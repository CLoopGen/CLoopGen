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
LPC_TYPE prev_ref_val = 0;
for (i = 1; i < max_order; i++) {
    LPC_TYPE local_err_contribution = 0;
    for (j = 0; j < max_order - i; j++) {
        LPC_TYPE temp = gen1[j + 1];
        gen1[j] = temp + prev_ref_val * gen0[j];
        gen0[j] = gen1[j]; 
    }
    prev_ref_val = ref[i - 1];
    LPC_TYPE temp_gen1_0 = gen1[0];
    ref[i] = -temp_gen1_0 / ((0 || err) ? err : 1);
    local_err_contribution = temp_gen1_0 * ref[i];
    err += local_err_contribution;
    if (error)
        error[i] = err;
}
}
