#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolling for better spatial locality
    uint8_t *src_ptr = src;
    int16_t *tmp_ptr = tmp;
    for (y = 0; y < height + 3; y++) {
        const int8_t f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3];
        uint8_t *s = src_ptr - 1;
        for (x = 0; x < width; x += 4) {
            // Process 4 elements at a time with consecutive access pattern
            tmp_ptr[x+0] = (f0 * s[x+0] + f1 * s[x+1] + f2 * s[x+2] + f3 * s[x+3]) >> 8;
            tmp_ptr[x+1] = (f0 * s[x+1] + f1 * s[x+2] + f2 * s[x+3] + f3 * s[x+4]) >> 8;
            tmp_ptr[x+2] = (f0 * s[x+2] + f1 * s[x+3] + f2 * s[x+4] + f3 * s[x+5]) >> 8;
            tmp_ptr[x+3] = (f0 * s[x+3] + f1 * s[x+4] + f2 * s[x+5] + f3 * s[x+6]) >> 8;
        }
        src_ptr += srcstride;
        tmp_ptr += 64;
    }
}
