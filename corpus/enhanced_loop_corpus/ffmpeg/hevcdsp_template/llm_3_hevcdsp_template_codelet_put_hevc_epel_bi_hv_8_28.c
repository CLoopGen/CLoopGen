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
    // Variant 2: Strided memory access – process every second element first, then the rest (interleaved access pattern)
    for (y = 0; y < height + 3; y++) {
        // First pass: even indices
        for (x = 0; x < width; x += 2) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 0;
        }
        // Second pass: odd indices
        for (x = 1; x < width; x += 2) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
