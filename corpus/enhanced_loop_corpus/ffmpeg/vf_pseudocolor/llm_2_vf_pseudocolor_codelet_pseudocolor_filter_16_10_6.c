#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern  uint16_t *_usr_index;
extern  uint16_t *src;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes width is even and processes two pixels per iteration to promote vectorization
    for (y = 0; y < height; y++) {
        uint16_t *idx_ptr = index;
        uint16_t *src_ptr = src;
        uint16_t *dst_ptr = dst;
        for (x = 0; x < width; x += 2) {
            int v0 = lut[idx_ptr[0] << 1];
            int v1 = lut[idx_ptr[1] << 1];

            dst_ptr[0] = (v0 >= 0 && v0 <= max) ? v0 : src_ptr[0];
            dst_ptr[1] = (v1 >= 0 && v1 <= max) ? v1 : src_ptr[1];

            idx_ptr += 2;
            src_ptr += 2;
            dst_ptr += 2;
        }
        index += ilinesize / 2;
        src += slinesize / 2;
        dst += dlinesize / 2;
    }
}
