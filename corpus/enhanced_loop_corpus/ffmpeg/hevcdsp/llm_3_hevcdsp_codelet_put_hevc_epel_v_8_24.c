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
    // Variant 2: Strided Memory Access via Pointer Arithmetic
    // Instead of indexing src[x ± k], use strided pointers to traverse vertical neighbors.
    // This emphasizes memory access along the column (strided pattern), useful in transpose-like scenarios.

    int16_t *dst_ptr = dst;
    uint8_t *src_top = src - srcstride; // Start from row above

    for (y = 0; y < height; y++) {
        uint8_t *src_prev = src_top + y * srcstride;         // y-1 row
        uint8_t *src_curr = src_prev + srcstride;            // y   row
        uint8_t *src_next = src_curr + srcstride;            // y+1 row
        uint8_t *src_next2 = src_next + srcstride;           // y+2 row

        for (x = 0; x < width; x++) {
            // Strided vertical access: each source comes from same column, different rows
            int sum = filter[0] * src_prev[x] +
                      filter[1] * src_curr[x] +
                      filter[2] * src_next[x] +
                      filter[3] * src_next2[x];
            dst_ptr[x] = sum >> 8;
        }
        dst_ptr += 64;
    }
}
