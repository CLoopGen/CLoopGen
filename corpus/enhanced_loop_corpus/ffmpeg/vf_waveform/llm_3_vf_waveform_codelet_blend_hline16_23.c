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
    // Variant 2: Strided memory access with increased stride (access every 2*step instead of step)
    int x;
    int effective_step = 2 * step;
    for (x = 0; x < width; x += effective_step) {
        dst[x] = v * o1 + dst[x] * o2;
    }
}
