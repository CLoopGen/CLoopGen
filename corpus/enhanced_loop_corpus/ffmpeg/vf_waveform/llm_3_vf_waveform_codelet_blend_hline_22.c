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
    // Variant 2: Strided memory access with increased stride (access every 2nd element in the original pattern)
    int doubled_step = step * 2;
    for (x = 0; x < width; x += doubled_step) {
        dst[x] = v * o1 + dst[x] * o2;
    }
}
