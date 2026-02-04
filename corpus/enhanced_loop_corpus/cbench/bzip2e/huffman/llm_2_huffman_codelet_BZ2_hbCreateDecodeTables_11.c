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
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element, adjusting bounds accordingly
    Int32 start = (minLen + 1) % 2 == 0 ? minLen + 1 : minLen + 2;
    for (i = start; i <= maxLen; i += 2)
        base[i] = ((limit[i - 1] + 1) << 1) - base[i];
}
