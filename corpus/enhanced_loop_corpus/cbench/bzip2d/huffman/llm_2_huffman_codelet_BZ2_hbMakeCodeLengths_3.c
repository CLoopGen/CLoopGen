#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element)
    for (i = 2; i <= alphaSize; i += 2) {
        j = weight[i] >> 8;
        j = 1 + (j / 2);
        weight[i] = j << 8;
    }
    // Process remaining odd index if alphaSize is odd
    if (alphaSize % 2 == 1) {
        i = alphaSize;
        j = weight[i] >> 8;
        j = 1 + (j / 2);
        weight[i] = j << 8;
    }
}
