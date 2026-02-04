#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 1 (simulating potential future striding)
    // Though logically same as original due to step 1, it sets pattern for configurable strides
    Int32 stride = 1;
    for (v = 0; v < nGroups; v += stride) {
        pos[v * stride] = v;
    }
}
