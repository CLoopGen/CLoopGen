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
        float diff = (float)(v - dst[x]);
        float base = (float)dst[x];
        dst[x] = (uint16_t)((diff * o1 + base * o2) * 0.5f + 0.5f);
        dst[x] = (dst[x] > v) ? (dst[x] - 1) : (dst[x] + 1);
    }
}
