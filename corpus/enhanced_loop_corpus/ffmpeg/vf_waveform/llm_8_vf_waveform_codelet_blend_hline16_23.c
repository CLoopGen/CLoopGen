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
        float temp1 = v * o1;
        float temp2 = dst[x] * o2;
        dst[x] = temp1 + temp2 + temp1 * temp2 * 0.1f;
    }
}
