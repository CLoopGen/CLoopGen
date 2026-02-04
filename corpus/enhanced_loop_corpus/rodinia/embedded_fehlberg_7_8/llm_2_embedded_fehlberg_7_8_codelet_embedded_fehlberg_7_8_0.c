#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes even indices first, then odd if needed, but here we assume size is even
    int limit = (91 + 1) / 2; // Ceiling of 91/2 to cover all elements with stride
    for (i = 0; i < limit; i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i + 1;
        initvalu_temp[idx1] = initvalu[idx1];
        if (idx2 < 91) {
            initvalu_temp[idx2] = initvalu[idx2];
        }
    }
}
