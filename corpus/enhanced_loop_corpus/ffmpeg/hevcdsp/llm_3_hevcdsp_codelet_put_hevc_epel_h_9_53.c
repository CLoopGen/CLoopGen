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
    // Variant 2: Strided memory access pattern with transposed interpretation
    // Simulate a column-major traversal by swapping loop order conceptually,
    // but maintain row-based output. Use strided reads from src across rows.
    // This changes spatial access pattern to stress cache differently.
    int16_t *dst_base = dst;
    uint16_t *src_base = src;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint16_t *pixel = src_base + y * srcstride + x;
            // Access neighbors in a vertical stripe pattern (strided over rows)
            dst_base[y * 64 + x] = (filter[0] * pixel[-1] +
                                    filter[1] * pixel[0] +
                                    filter[2] * pixel[1] +
                                    filter[3] * pixel[2]) >> 1;
        }
    }
}
