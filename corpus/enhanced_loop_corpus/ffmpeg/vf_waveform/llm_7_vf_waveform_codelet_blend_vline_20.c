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
    uint8_t* local_dst = dst;
    int local_linesize = linesize * step;
    float scaled_o1 = v * o1;
    float scaled_o2 = o2;
    int i = 0;
    for (y = 0; y < height; y += step) {
        int offset = i * local_linesize;
        local_dst[offset] = (uint8_t)(scaled_o1 + local_dst[offset] * scaled_o2);
        i++;
    }
    dst = local_dst + i * local_linesize; // update original dst if needed by caller
}
