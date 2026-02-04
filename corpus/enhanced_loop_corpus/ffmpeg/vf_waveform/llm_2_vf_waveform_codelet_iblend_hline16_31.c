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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *d = dst;
    for (x = 0; x < width; x += step, d += step) {
        *d = (v - *d) * o1 + *d * o2;
    }
}
