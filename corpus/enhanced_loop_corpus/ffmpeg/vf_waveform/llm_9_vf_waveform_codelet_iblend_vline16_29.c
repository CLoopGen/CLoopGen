#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int linesize;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern uint16_t *dst;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += step) {
    float temp1 = (v - dst[0]) * o1;
    float temp2 = dst[0] * o2;
    dst[0] = temp1 + temp2;
    dst[2] = temp1 * 0.5f + temp2 * 0.5f;
    dst[4] = temp1 * 0.3f + temp2 * 0.7f;
    dst += (linesize / 2) * step;
}
}
