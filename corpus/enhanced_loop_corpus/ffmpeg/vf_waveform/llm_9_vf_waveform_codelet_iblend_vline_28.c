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
    int step2 = step * 2;
    for (y = 0; y < height; y += step2) {
        dst[0] = (v - dst[0]) * o1 + dst[0] * o2;
        if (y + step < height) {
            dst[linesize * step] = (v - dst[linesize * step]) * o1 + dst[linesize * step] * o2;
        }
        dst += linesize * step2;
    }
}
