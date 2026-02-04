#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element first, then the others (interleaved stride pattern)
    for (y = 0; y < height; y++) {
        int16_t *dst_ptr = dst;
        const uint8_t *src_base = src;
        // Process even indices first with stride 2
        for (x = 0; x < width; x += 2) {
            dst_ptr[x] = (filter[0] * src_base[x - 1] + filter[1] * src_base[x] + filter[2] * src_base[x + 1] + filter[3] * src_base[x + 2]) >> 0;
        }
        // Then process odd indices
        for (x = 1; x < width; x += 2) {
            dst_ptr[x] = (filter[0] * src_base[x - 1] + filter[1] * src_base[x] + filter[2] * src_base[x + 1] + filter[3] * src_base[x + 2]) >> 0;
        }
        src += srcstride;
        dst += 64;
    }
}
