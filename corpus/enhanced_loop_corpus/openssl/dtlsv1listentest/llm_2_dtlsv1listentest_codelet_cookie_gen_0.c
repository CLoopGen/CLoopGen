#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with block write pattern (unrolled by 4)
    for (i = 0; i < 20; i += 4) {
        *cookie++ = i;
        if (i + 1 < 20) *cookie++ = i + 1;
        if (i + 2 < 20) *cookie++ = i + 2;
        if (i + 3 < 20) *cookie++ = i + 3;
    }
}
