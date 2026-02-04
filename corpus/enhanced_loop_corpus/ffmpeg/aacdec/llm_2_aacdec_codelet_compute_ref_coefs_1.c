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
    // Variant 1: Consecutive Memory Access Pattern
    // Reversed iteration to enable consecutive writes and reads in gen0/gen1
    // by processing j from high to low, improving spatial locality

    for (i = 1; i < max_order; i++) {
        int upper_bound = max_order - i;
        for (j = upper_bound - 1; j >= 0; j--) {
            gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
            gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
