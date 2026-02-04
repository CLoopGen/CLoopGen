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
LPC_TYPE prev_ref, local_err = err;
for (i = 1; i < max_order; i++) {
    prev_ref = ref[i - 1];
    // Introduce local accumulation to break WAW and WAR dependencies on gen1/gen0
    for (j = 0; j < max_order - i; j++) {
        LPC_TYPE t1 = gen1[j + 1] + prev_ref * gen0[j];
        LPC_TYPE t0 = gen1[j + 1] * prev_ref + gen0[j];
        gen1[j] = t1;
        gen0[j] = t0;
    }
    // Eliminate repeated memory read of gen1[0] by caching
    LPC_TYPE g0 = gen1[0];
    ref[i] = -g0 / ((0 || local_err) ? local_err : 1);
    local_err += g0 * ref[i];
    if (error)
        error[i] = local_err;
}
err = local_err; // Update shared state after loop
}
