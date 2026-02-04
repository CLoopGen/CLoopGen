#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, then fill in)
    Int32 j;
    for (j = (alphaSize + 1) / 2 - 1; j >= 0; j--) {
        i = 2 * j;
        if (i < alphaSize) {
            weight[i + 1] = (freq[i] == 0 ? 1 : freq[i]) << 8;
        }
        if (i + 1 < alphaSize) {
            weight[i + 2] = (freq[i + 1] == 0 ? 1 : freq[i + 1]) << 8;
        }
    }
}
