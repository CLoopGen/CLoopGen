#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int height;
extern int linesize;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = v * o1;
    for (y = 0; y < height; y += step) {
        float accumulator = dst[0] * o2 + temp;
        dst[0] = (uint8_t)accumulator;
        dst += linesize * step;
    }
}
