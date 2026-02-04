#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern uint16_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by 2
    int i;
    for (i = 0; i < width - 1; i += 2 * step) {
        dst[i] = v * o1 + dst[i] * o2;
        dst[i + step] = v * o1 + dst[i + step] * o2;
    }
    // Handle remaining element if width is odd
    if (i < width) {
        dst[i] = v * o1 + dst[i] * o2;
    }
}
