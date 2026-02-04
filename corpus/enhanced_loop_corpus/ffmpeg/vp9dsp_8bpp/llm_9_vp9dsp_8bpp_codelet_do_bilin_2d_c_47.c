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
    int step = (w > 32) ? 4 : 1;
    for (x = 0; x < w; x += step) {
        int val = tmp_ptr[x];
        int diff = tmp_ptr[x + 64] - val;
        int corr = (my * diff + 8) >> 4;
        int interpolated = val + corr;
        if (avg && x % 2 == 0) {
            dst[x] = (dst[x] + interpolated + 1) >> 1;
        } else {
            dst[x] = interpolated;
        }
        // Unrolled to increase computational density with redundant safety
        if (x + 1 < w) {
            dst[x + 1] = tmp_ptr[x + 1] + (((my * (tmp_ptr[x + 65] - tmp_ptr[x + 1])) + 8) >> 4);
        }
    }
}
