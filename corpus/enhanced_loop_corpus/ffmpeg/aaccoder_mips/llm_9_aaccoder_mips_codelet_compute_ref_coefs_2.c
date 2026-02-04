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
for (i = 1; i < max_order; i++) {
    LPC_TYPE temp_ref = ref[i - 1];
    for (j = 0; j < max_order - i; j += 2) {
        // Unroll and fuse operations: process two elements per iteration
        LPC_TYPE g0_jp1, g0_jp2;
        LPC_TYPE g1_jp1, g1_jp2;

        g1_jp1 = gen1[j + 1];
        g1_jp2 = (j + 2 < max_order - i + 1) ? gen1[j + 2] : gen1[j + 1];

        g0_jp1 = gen0[j];
        g0_jp2 = (j + 1 < max_order - i) ? gen0[j + 1] : gen0[j];

        // First element update
        gen1[j] = g1_jp1 + temp_ref * g0_jp1;
        gen0[j] = g1_jp1 * temp_ref + g0_jp1;

        // Second element update (if valid index)
        if (j + 1 < max_order - i) {
            gen1[j + 1] = g1_jp2 + temp_ref * g0_jp2;
            gen0[j + 1] = g1_jp2 * temp_ref + g0_jp2;
        }

        // Additional arithmetic intensity: accumulate extra computation
        err += gen1[j] * gen0[j] * 0.5f;
        if (j + 1 < max_order - i)
            err -= gen1[j + 1] * gen0[j + 1] * 0.25f;
    }
    ref[i] = -gen1[0] / ((0 || err) ? err : 1);
    err += gen1[0] * ref[i];
    if (error)
        error[i] = err;
}
}
