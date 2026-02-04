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
    for (int outer = 0; outer < w; outer += 16) {
        for (int inner = 0; inner < 16 && (outer + inner) < w; inner++) {
            int idx = outer + inner;
            if (avg) {
                dst[idx] = (dst[idx] + (tmp_ptr[idx] + ((my * (tmp_ptr[idx + 64] - tmp_ptr[idx]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[idx] = (tmp_ptr[idx] + ((my * (tmp_ptr[idx + 64] - tmp_ptr[idx]) + 8) >> 4));
            }
        }
    }
}
