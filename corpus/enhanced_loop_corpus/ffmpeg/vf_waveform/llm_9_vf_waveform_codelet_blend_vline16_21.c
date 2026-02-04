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
for (y = 0; y < height; y += step * 2) {
    float temp1 = dst[0] * o2;
    float temp2 = dst[linesize / 2] * o2;
    dst[0] = v * o1 + temp1;
    dst[linesize / 2] = v * o1 + temp2;
    dst += (linesize / 2) * step * 2;
}
}
