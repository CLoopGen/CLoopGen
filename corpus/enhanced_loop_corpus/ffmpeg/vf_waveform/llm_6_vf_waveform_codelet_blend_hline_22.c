#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (x = 0; x < width; x += step) {
        temp = dst[x] * o2;
        dst[x] = v * o1 + temp;
    }
}
