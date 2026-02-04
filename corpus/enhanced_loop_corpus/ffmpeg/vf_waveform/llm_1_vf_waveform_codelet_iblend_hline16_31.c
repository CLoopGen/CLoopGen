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
    for (int outer = 0; outer < step; ++outer) {
        for (x = outer; x < width; x += step) {
            dst[x] = (v - dst[x]) * o1 + dst[x] * o2;
        }
    }
}
