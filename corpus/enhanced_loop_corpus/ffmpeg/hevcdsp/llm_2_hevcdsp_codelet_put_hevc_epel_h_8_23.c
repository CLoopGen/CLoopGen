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
    // Variant 1: Consecutive memory access with unrolled inner loop (stride-1 access)
    for (y = 0; y < height; y++) {
        int16_t *dst_ptr = dst;
        const uint8_t *src_ptr = src;
        for (x = 0; x < width - 3; x += 4) {
            // Unroll and use consecutive access pattern for better cache utilization
            dst_ptr[x]   = (filter[0] * src_ptr[x - 1] + filter[1] * src_ptr[x] + filter[2] * src_ptr[x + 1] + filter[3] * src_ptr[x + 2]) >> 0;
            dst_ptr[x+1] = (filter[0] * src_ptr[x]   + filter[1] * src_ptr[x+1] + filter[2] * src_ptr[x+2] + filter[3] * src_ptr[x+3]) >> 0;
            dst_ptr[x+2] = (filter[0] * src_ptr[x+1] + filter[1] * src_ptr[x+2] + filter[2] * src_ptr[x+3] + filter[3] * src_ptr[x+4]) >> 0;
            dst_ptr[x+3] = (filter[0] * src_ptr[x+2] + filter[1] * src_ptr[x+3] + filter[2] * src_ptr[x+4] + filter[3] * src_ptr[x+5]) >> 0;
        }
        // Handle remaining elements
        for (; x < width; x++) {
            dst_ptr[x] = (filter[0] * src_ptr[x - 1] + filter[1] * src_ptr[x] + filter[2] * src_ptr[x + 1] + filter[3] * src_ptr[x + 2]) >> 0;
        }
        src += srcstride;
        dst += 64;
    }
}
