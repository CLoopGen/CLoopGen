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
    int i;
    float temp;
    for (i = 0; i < width; i += step) {
        temp = (float)(v * o1) + (float)(dst[i] * o2);
        dst[i] = (uint16_t)temp;
    }
}
