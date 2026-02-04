#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with boundary check
    // This variant accesses weight and freq arrays with a step of 2, unrolling the original behavior
    // into two separate phases to maintain correctness while changing access pattern.
    for (i = 0; i < alphaSize; i += 2) {
        weight[i + 1] = (freq[i] == 0 ? 1 : freq[i]) << 8;
        if (i + 1 < alphaSize) {
            weight[i + 2] = (freq[i + 1] == 0 ? 1 : freq[i + 1]) << 8;
        }
    }
}
