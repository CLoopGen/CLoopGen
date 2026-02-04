#include <stdio.h>

#include <inttypes.h>

extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    int start = 2;
    int end = 9;  // (6 + 3) = 9
    for (i = start; i < end - 1; i += 2) {
        *q++ = 0;
        *q++ = 0;
    }
    // Handle remaining iteration if needed
    if (i < end) {
        *q++ = 0;
    }
}
