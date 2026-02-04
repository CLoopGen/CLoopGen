#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *x[];
extern float *x_lp;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements at 2*i-1, 2*i, and 2*i+1, we reorganize the access pattern
    // to use a fixed stride on a transformed index base, improving predictability.
    float *x1 = x[1]; // Local pointer for clarity and potential optimization
    for (int i = 1; i < len >> 1; i++) {
        int base_idx = 2 * i;
        x_lp[i] += 0.5F * (0.5F * (x1[base_idx - 1] + x1[base_idx + 1]) + x1[base_idx]);
    }
}
