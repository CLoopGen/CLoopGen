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
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // This changes the access pattern from sequential to strided, assuming maxLen accounts for valid range
    for (i = minLen; i <= maxLen; i += 2) {
        vec += (base[i + 2] - base[i]);  // Strided difference with step 2
        limit[i] = vec - 1;
        vec <<= 1;
    }
}
