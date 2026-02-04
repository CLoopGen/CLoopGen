#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t coeffs[16];
extern int32_t *sig;
extern int64_t e;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle pairs
    for (i = 0; i < 16; i += 2) {
        e += ((int64_t)(sig[i]) * (int64_t)(coeffs[i]));
        if (i + 1 < 16) {
            e += ((int64_t)(sig[i + 1]) * (int64_t)(coeffs[i + 1]));
        }
    }
}
