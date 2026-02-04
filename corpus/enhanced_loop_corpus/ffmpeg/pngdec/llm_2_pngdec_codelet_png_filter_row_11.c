#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (; i >= 3; i -= 4) {
        dst[i - 0] = a = ((a) + (src[i - 0]));
        if (4 == 1)
            continue;
        dst[i - 1] = b = ((b) + (src[i - 1]));
        if (4 == 2)
            continue;
        dst[i - 2] = g = ((g) + (src[i - 2]));
        if (4 == 3)
            continue;
        dst[i - 3] = r = ((r) + (src[i - 3]));
    }
}
