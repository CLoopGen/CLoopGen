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
    for (y = 0; y < height; y += step) {
        float temp1 = dst[0] * o2;
        float temp2 = (v - dst[0]) * o1;
        dst[0] = temp1 + temp2;
        dst += linesize * step;
    }
}
