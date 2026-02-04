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
    int temp = v;
    for (y = 0; y < height; y += step) {
        uint16_t prev_val = dst[0];
        dst[0] = (temp - prev_val) * o1 + prev_val * o2;
        temp = temp + 1; // Introduce WAW dependency on 'temp' across iterations
        dst += (linesize / 2) * step;
    }
}
