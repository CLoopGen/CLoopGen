#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 *base;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 i;
extern Int32 vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This changes the access pattern to every second element, reducing total iterations by half
    // and accessing base[i+2] and base[i] with step size 2. Adjusted loop bounds accordingly.
    Int32 stride = 2;
    for (i = minLen; i <= maxLen - 1; i += stride) {
        vec += (base[i + 2] - base[i]);
        limit[i] = vec - 1;
        vec <<= 1;
    }
}
