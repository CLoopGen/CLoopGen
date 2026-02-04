#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 4, processing 4 elements per iteration
    int limit = size - (size % 4); // Make sure we don't go out of bounds
    for (; i <= limit - 4; i += 4) {
        dst[i + 0] = r = (((((r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
        dst[i + 1] = g = (((((g) + (last[i + 1])) >> 1) + (src[i + 1])) & 255);
        dst[i + 2] = b = (((((b) + (last[i + 2])) >> 1) + (src[i + 2])) & 255);
        dst[i + 3] = a = (((((a) + (last[i + 3])) >> 1) + (src[i + 3])) & 255);
    }
    // Handle remaining elements with original logic
    for (; i <= size - 1; i += 1) {
        dst[i + 0] = r = (((((r) + (last[i + 0])) >> 1) + (src[i + 0])) & 255);
        if (1 == 1)
            continue;
        dst[i + 1] = g = (((((g) + (last[i + 1])) >> 1) + (src[i + 1])) & 255);
        if (1 == 2)
            continue;
        dst[i + 2] = b = (((((b) + (last[i + 2])) >> 1) + (src[i + 2])) & 255);
        if (1 == 3)
            continue;
        dst[i + 3] = a = (((((a) + (last[i + 3])) >> 1) + (src[i + 3])) & 255);
    }
}
