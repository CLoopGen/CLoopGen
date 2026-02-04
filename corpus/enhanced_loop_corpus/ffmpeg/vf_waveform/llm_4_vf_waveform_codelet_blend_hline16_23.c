#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern uint16_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < width; x += step) {
        if (v > 0) {
            dst[x] = v * o1 + dst[x] * o2;
        } else {
            dst[x] = dst[x] * o2;
        }
    }
}
