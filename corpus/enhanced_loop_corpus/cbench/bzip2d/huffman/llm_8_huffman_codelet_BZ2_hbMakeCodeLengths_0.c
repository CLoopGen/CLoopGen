#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled operations
    // Trip count adjusted to process two elements per iteration, reducing loop overhead
    for (i = 0; i < alphaSize; i += 2) {
        Int32 idx1 = i;
        Int32 idx2 = i + 1;
        weight[idx1 + 1] = ((freq[idx1] == 0 ? 1 : freq[idx1]) << 8) + ((freq[idx1] + 1) >> 1);
        if (idx2 < alphaSize) {
            weight[idx2 + 1] = ((freq[idx2] == 0 ? 1 : freq[idx2]) << 8) + ((freq[idx2] + 1) >> 1);
        }
    }
}
