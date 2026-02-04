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
    int outer_limit = (w + 31) / 32;
    for (int i = 0; i < outer_limit; i++) {
        int start = i * 32;
        int end = (start + 32 < w) ? start + 32 : w;
        for (int j = start; j < end; j++) {
            if (avg) {
                dst[j] = (dst[j] + (tmp_ptr[j] + ((my * (tmp_ptr[j + 64] - tmp_ptr[j]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[j] = (tmp_ptr[j] + ((my * (tmp_ptr[j + 64] - tmp_ptr[j]) + 8) >> 4));
            }
        }
    }
}
