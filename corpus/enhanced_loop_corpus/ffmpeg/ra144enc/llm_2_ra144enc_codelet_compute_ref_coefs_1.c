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



void loop() {
    // Variant 1: Consecutive Memory Access via Array Reversal Emulation
    // Instead of accessing gen1[j+1] and gen0[j], we shift the base pointer to create consecutive forward access pattern
    LPC_TYPE *gen1_base = gen1 + 1;
    LPC_TYPE *gen0_base = gen0;
    
    for (i = 1; i < max_order; i++) {
        LPC_TYPE ref_im1 = ref[i - 1];
        for (j = 0; j < max_order - i; j++) {
            gen1[j] = gen1_base[j] + ref_im1 * gen0_base[j];
            gen0[j] = gen1_base[j] * ref_im1 + gen0_base[j];
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
