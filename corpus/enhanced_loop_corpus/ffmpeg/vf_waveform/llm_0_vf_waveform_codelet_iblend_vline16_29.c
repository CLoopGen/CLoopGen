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
    for (int outer = 0; outer < step; outer++) {
        for (y = outer; y < height; y += step) {
            dst[0] = (v - dst[0]) * o1 + dst[0] * o2;
            dst += (linesize / 2) * step;
        }
        dst = (uint16_t*)((char*)dst - (ptrdiff_t)((height / step) * (linesize / 2) * step * sizeof(uint16_t)));
        dst += outer * (linesize / 2);
    }
}
