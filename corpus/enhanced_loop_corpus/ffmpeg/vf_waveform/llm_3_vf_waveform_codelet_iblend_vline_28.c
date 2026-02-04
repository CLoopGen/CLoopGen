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
    for (y = 0; y < height; y += step) {
        uint8_t *current_dst = dst + y * linesize;
        for (int s = 0; s < step && (y + s) < height; s++) {
            current_dst[s * linesize] = (v - current_dst[s * linesize]) * o1 + current_dst[s * linesize] * o2;
        }
    }
}
