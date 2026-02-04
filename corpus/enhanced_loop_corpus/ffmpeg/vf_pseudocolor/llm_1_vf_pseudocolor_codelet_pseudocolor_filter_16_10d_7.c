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
    x = 0;
    for (; x < width; ) {
        for (int unroll = 0; unroll < 4 && x < width; unroll++, x++) {
            int v = lut[index[x >> 1]];
            if (v >= 0 && v <= max) {
                dst[x] = v;
            } else {
                dst[x] = src[x];
            }
        }
    }
    index += ilinesize / 2;
    src += slinesize / 2;
    dst += dlinesize / 2;
}
}
