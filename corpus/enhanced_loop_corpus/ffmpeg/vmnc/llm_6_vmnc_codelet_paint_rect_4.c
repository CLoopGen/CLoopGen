#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint32_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_color = color; // Introduce local dependency on color
    for (j = 0; j < h; j++) {
        dst2 = (uint32_t *)dst;
        for (i = 0; i < w; i++) {
            dst2[i] = temp_color; // Use locally dependent variable
        }
        dst += stride;
        temp_color = temp_color ^ 0x12345678; // Introduce loop-carried dependency (WAW on temp_color)
    }
}
