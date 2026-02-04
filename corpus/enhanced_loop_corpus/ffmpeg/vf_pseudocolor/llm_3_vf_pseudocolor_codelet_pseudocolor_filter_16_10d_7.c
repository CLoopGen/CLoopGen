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
for (y = 0; y < height; y++) {
    ptrdiff_t i_offset = y * (ilinesize / 2);
    ptrdiff_t s_offset = y * (slinesize / 2);
    ptrdiff_t d_offset = y * (dlinesize / 2);
    for (x = 0; x < width; x++) {
        int idx = (index[i_offset + (x >> 1)]);
        int v = lut[idx];
        dst[d_offset + x] = (v >= 0 && v <= max) ? v : src[s_offset + x];
    }
}
}
