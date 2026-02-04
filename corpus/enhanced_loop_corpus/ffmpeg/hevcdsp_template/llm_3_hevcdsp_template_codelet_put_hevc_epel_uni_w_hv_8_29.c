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
    // Variant 2: Strided memory access – process every second element first, then the in-betweens (interleaved stride pattern)
    uint8_t *src_base = src;
    int16_t *tmp_base = tmp;
    for (y = 0; y < height + 3; y++) {
        // First pass: even indices using stride of 2
        for (x = 0; x < width; x += 2) {
            int offset = x - 1;
            tmp_base[x] = (filter[0] * src_base[offset + 0] +
                           filter[1] * src_base[offset + 1] +
                           filter[2] * src_base[offset + 2] +
                           filter[3] * src_base[offset + 3]) >> 8;
        }
        // Second pass: odd indices with same kernel but offset start
        for (x = 1; x < width; x += 2) {
            int offset = x - 1;
            tmp_base[x] = (filter[0] * src_base[offset + 0] +
                           filter[1] * src_base[offset + 1] +
                           filter[2] * src_base[offset + 2] +
                           filter[3] * src_base[offset + 3]) >> 8;
        }
        src_base += srcstride;
        tmp_base += 64;
    }
}
