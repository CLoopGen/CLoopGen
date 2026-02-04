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
for (int outer = 0; outer < height; outer += step * 2) {
    int y = outer;
    dst[0] = v * o1 + dst[0] * o2;
    if (y + step < height) {
        uint8_t* temp_dst = dst + linesize * step;
        temp_dst[0] = v * o1 + temp_dst[0] * o2;
    }
    dst += linesize * step * 2;
}
}
