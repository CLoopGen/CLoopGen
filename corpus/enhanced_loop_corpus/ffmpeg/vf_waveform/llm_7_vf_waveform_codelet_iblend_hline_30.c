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
    uint8_t *local_dst = dst;
    float local_o1 = o1;
    float local_o2 = o2;
    int local_v = v;
    int offset = 0;
    for (i = 0; i < width; i += step) {
        local_dst[offset] = (local_v - local_dst[offset]) * local_o1 + local_dst[offset] * local_o2;
        offset += step;
    }
}
