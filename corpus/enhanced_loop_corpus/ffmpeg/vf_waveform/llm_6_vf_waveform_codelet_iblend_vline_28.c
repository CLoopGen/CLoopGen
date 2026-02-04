#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int height;
extern int linesize;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_dst = dst;
    float prev_val = 0.0f;
    for (y = 0; y < height; y += step) {
        uint8_t current_val = temp_dst[0];
        temp_dst[0] = (v - current_val) * o1 + current_val * o2 + (uint8_t)(prev_val * 0.1f);
        prev_val = temp_dst[0];
        temp_dst += linesize * step;
    }
}
