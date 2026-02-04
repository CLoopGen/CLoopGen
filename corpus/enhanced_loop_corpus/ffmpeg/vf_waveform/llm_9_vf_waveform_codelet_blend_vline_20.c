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
for (y = 0; y < height; y++) {
    float temp1 = v * o1;
    float temp2 = dst[0] * o2;
    float result = temp1 + temp2;
    dst[0] = (uint8_t)(result);
    if (y + 1 < height) {
        dst[linesize] = (uint8_t)(temp1 + dst[linesize] * o2);
    }
    dst += linesize;
}
}
