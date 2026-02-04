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
    // Variant 1: Consecutive memory access with unrolled filtering (stride-1 access)
    for (y = 0; y < height + 3; y++) {
        uint8_t *s = src;
        int16_t *t = tmp;
        // Unroll the inner loop by 2x for better spatial locality and consecutive access
        for (x = 0; x <= width - 2; x += 2) {
            t[x]     = (filter[0] * s[x - 1] + filter[1] * s[x] + filter[2] * s[x + 1] + filter[3] * s[x + 2]) >> 0;
            t[x + 1] = (filter[0] * s[x]     + filter[1] * s[x + 1] + filter[2] * s[x + 2] + filter[3] * s[x + 3]) >> 0;
        }
        // Handle remaining element if width is odd
        if (x < width) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
