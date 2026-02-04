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
    // Variant 2: Consecutive memory access using a pointer with forward iteration
    uint8_t *ptr = dst;
    for (x = 0; x < width; x += step, ptr += step) {
        *ptr = (v - *ptr) * o1 + *ptr * o2;
    }
}
