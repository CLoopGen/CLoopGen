#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t len;
extern uint32_t stride;
extern float c;
extern float s;
extern float *Xptr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by unrolling two iterations (where possible)
    // Assumes len - stride >= 2 for partial unrolling; handles remainder with adjusted loop
    uint32_t n = len - stride;
    for (i = 0; i < (n & ~1U); i += 2) { // Process two elements per iteration
        // First iteration of original loop
        float x1_1 = Xptr[0];
        float x2_1 = Xptr[stride];
        Xptr[stride] = c * x2_1 + s * x1_1;
        *Xptr++ = c * x1_1 - s * x2_1;

        // Second iteration
        float x1_2 = Xptr[0];
        float x2_2 = Xptr[stride];
        Xptr[stride] = c * x2_2 + s * x1_2;
        *Xptr++ = c * x1_2 - s * x2_2;
    }
    // Handle any remaining single iteration
    if (i < n) {
        float x1 = Xptr[0];
        float x2 = Xptr[stride];
        Xptr[stride] = c * x2 + s * x1;
        *Xptr++ = c * x1 - s * x2;
        i++;
    }
}
