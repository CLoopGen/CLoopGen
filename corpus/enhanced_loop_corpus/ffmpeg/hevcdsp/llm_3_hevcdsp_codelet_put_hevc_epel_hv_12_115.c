#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed increments
    for (y = 0; y < height + 3; y++) {
        uint16_t *s = src + y * srcstride;
        int16_t *t = tmp + y * 64;
        for (x = 0; x < width; x += 2) {  // Process two elements per iteration (strided by 2)
            t[x]     = (int16_t)(((int)filter[0] * s[x - 1] +
                                 filter[1] * s[x] +
                                 filter[2] * s[x + 1] +
                                 filter[3] * s[x + 2]) >> 4);
            if (x + 1 < width) {
                t[x + 1] = (int16_t)(((int)filter[0] * s[x] +
                                     filter[1] * s[x + 1] +
                                     filter[2] * s[x + 2] +
                                     filter[3] * s[x + 3]) >> 4);
            }
        }
    }
}
