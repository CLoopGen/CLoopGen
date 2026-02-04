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
    float scale = o1 + o2;
    for (x = 0; x < width; x += step) {
        float temp = (float)(v - dst[x]);
        temp *= o1;
        temp += (float)dst[x] * o2;
        dst[x] = (uint8_t)(temp / scale);
    }
}
