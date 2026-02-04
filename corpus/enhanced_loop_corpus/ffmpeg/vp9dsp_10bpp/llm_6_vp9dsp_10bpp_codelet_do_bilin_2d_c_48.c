#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int w;
extern int my;
extern int avg;
extern uint16_t *tmp_ptr;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < w; i++) {
        uint16_t temp_val = tmp_ptr[i];
        uint16_t neighbor_val = tmp_ptr[i + 64];
        int diff = neighbor_val - temp_val;
        int adjusted = (my * diff + 8) >> 4;
        int interpolated = temp_val + adjusted;
        if (avg && i > 0) {
            dst[i] = (dst[i-1] + interpolated + 1) >> 1;
        } else {
            dst[i] = interpolated;
        }
    }
}
