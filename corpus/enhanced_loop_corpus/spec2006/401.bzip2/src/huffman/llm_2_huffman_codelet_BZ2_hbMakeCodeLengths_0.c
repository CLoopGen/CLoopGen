#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolled to process two elements per iteration
    // This changes the access pattern from sequential to strided and reduces loop iterations by half
    Int32 j;
    for (j = 0; j < alphaSize; j += 2) {
        Int32 idx1 = j;
        weight[idx1 + 1] = (freq[idx1] == 0 ? 1 : freq[idx1]) << 8;
        if (j + 1 < alphaSize) {
            Int32 idx2 = j + 1;
            weight[idx2 + 1] = (freq[idx2] == 0 ? 1 : freq[idx2]) << 8;
        }
    }
}
