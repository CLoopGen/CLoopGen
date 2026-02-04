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



void loop() {
    ptrdiff_t stride = 2;
    for (y = 0; y < height; y += 1) {
        for (x = 0; x < width; x += 1) {
            ptrdiff_t index_offset = ((y * stride) * ilinesize) + (x * stride);
            ptrdiff_t src_offset = y * slinesize + x;
            ptrdiff_t dst_offset = y * dlinesize + x;
            int v = lut[index[index_offset]];
            dst[dst_offset] = (v >= 0 && v <= max) ? v : src[src_offset];
        }
    }
}
