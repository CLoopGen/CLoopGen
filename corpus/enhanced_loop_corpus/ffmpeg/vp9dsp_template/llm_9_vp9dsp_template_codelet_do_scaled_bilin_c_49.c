#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int my;
extern int avg;
extern uint8_t *tmp_ptr;
extern uint8_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (w > 32) ? 1 : 2;
    for (x = 0; x < w; x++) {
        int offset = x + 64;
        int diff = tmp_ptr[offset] - tmp_ptr[x];
        int adjusted = (my * diff + 8) >> 4;
        int temp_val = tmp_ptr[x] + adjusted;

        if (avg && (x % step == 0)) {
            dst[x] = (dst[x] + temp_val + 1) >> 1;
        } else if (!avg) {
            dst[x] = temp_val;
        }
    }
}
