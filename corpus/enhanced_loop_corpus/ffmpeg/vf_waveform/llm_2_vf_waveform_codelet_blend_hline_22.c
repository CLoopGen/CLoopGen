#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by 2
    int i;
    for (i = 0; i <= width - 2 * step; i += 2 * step) {
        dst[i] = v * o1 + dst[i] * o2;
        dst[i + step] = v * o1 + dst[i + step] * o2;
    }
    // Handle remaining elements
    for (; i < width; i += step) {
        dst[i] = v * o1 + dst[i] * o2;
    }
}
