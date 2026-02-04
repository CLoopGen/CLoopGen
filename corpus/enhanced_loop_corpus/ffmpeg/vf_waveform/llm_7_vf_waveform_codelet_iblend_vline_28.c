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
    int effective_step = step * linesize;
    int i;
    for (i = 0; i < height; i += step, temp_dst += effective_step) {
        uint8_t val = temp_dst[0];
        uint8_t computed = (v - val) * o1 + val * o2;
        temp_dst[0] = computed;
    }
}
