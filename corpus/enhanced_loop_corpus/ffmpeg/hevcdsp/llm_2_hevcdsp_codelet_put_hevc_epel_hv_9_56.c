#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Re-indexed tmp Access
    // Instead of strided access (x-64, x, x+64, x+128), we reorganize tmp to be accessed consecutively
    // by pre-offsetting the base pointer. This improves cache locality.
    int16_t *tmp_base = tmp - 64;  // Pre-adjust base to eliminate subtraction in inner loop
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int offset = x;
            dst[x] = (filter[0] * tmp_base[offset] +
                      filter[1] * tmp_base[offset + 64] +
                      filter[2] * tmp_base[offset + 128] +
                      filter[3] * tmp_base[offset + 192]) >> 6;
        }
        tmp_base += 64;
        dst += 64;
    }
}
