#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 *base;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled effect
    // Trip count reduced by factor of 2 with dual updates per iteration to increase operations per loop cycle
    Int32 step = 2;
    for (i = minLen + 1; i <= maxLen; i += step) {
        if (i <= maxLen)
            base[i] = ((limit[i - 1] + 2) << 2) + base[i] * 3 - 5;
        if (i + 1 <= maxLen)
            base[i + 1] = ((limit[i] + 2) << 2) + base[i + 1] * 3 - 5;
    }
}
