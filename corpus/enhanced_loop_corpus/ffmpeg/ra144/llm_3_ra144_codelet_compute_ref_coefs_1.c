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
    // Variant 2: Strided memory access with reverse loop index (reverse traversal with stride simulation via indexing)
    for (i = 1; i < max_order; i++) {
        LPC_TYPE temp_ref = ref[i - 1];
        int upper = max_order - i;
        // Traverse backwards to change access pattern (reverse strided-like behavior)
        for (j = upper - 1; j >= 0; j--) {
            LPC_TYPE g1_next = gen1[j + 1];
            LPC_TYPE g0_val = gen0[j];
            gen1[j] = g1_next + temp_ref * g0_val;
            gen0[j] = g1_next * temp_ref + g0_val;
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
