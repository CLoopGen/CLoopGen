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
    uint16_t prev = dst[0];
    for (i = step; i < width; i += step) {
        uint16_t current = dst[i];
        dst[i] = v * o1 + prev * o2;
        prev = current;
    }
}
