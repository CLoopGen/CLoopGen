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
        if (dst[0] > v) {
            dst[0] = v * o1 + dst[0] * o2;
        } else {
            dst[0] = v * o2 + dst[0] * o1;
        }
        dst += (linesize / 2) * step;
    }
}
