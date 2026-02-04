#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing restructured for linear traversal
    int8_t *filter_local = filter;
    uint8_t *src_local;
    int16_t *tmp_local;

    for (y = 0; y < height + 7; y++) {
        src_local = src + y * srcstride;
        tmp_local = tmp + y * 64;
        for (x = 0; x < width; x++) {
            int sum = 0;
            const uint8_t *s = src_local + x;
            sum += filter_local[0] * s[-3];
            sum += filter_local[1] * s[-2];
            sum += filter_local[2] * s[-1];
            sum += filter_local[3] * s[0];
            sum += filter_local[4] * s[1];
            sum += filter_local[5] * s[2];
            sum += filter_local[6] * s[3];
            sum += filter_local[7] * s[4];
            tmp_local[x] = sum >> (8 - 8);
        }
    }
}
