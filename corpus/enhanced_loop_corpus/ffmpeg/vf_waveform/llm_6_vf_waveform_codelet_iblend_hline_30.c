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
    int i;
    float temp;
    for (i = 0; i < width; i += step) {
        temp = (v - dst[i]) * o1 + dst[i] * o2;
        dst[i] = temp;
    }
}
