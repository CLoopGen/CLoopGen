#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Unrolled Accumulation
    // Instead of strided access in the inner loop, we precompute base pointers and access src consecutively
    // This improves cache locality by reducing repeated indexing arithmetic.
    for (y = 0; y < height; y++) {
        int16_t *dst_ptr = &dst[x];  // Base destination pointer
        uint16_t *src_base = &src[-3];  // Adjust base to earliest accessed offset for linear indexing

        for (x = 0; x < width; x++) {
            uint16_t *src_ptr = &src_base[x + 3];  // Align to current x (so src[x] is at src_base[x+3])
            int32_t sum = filter[0] * src_ptr[-3] +
                          filter[1] * src_ptr[-2] +
                          filter[2] * src_ptr[-1] +
                          filter[3] * src_ptr[0] +
                          filter[4] * src_ptr[1] +
                          filter[5] * src_ptr[2] +
                          filter[6] * src_ptr[3] +
                          filter[7] * src_ptr[4];
            dst_ptr[x] = sum >> 1;
        }
        src += srcstride;
        dst += 64;
    }
}
