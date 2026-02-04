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
    for (x = 0; x < width - 1; x += 2) {
        int v0 = lut[index[x >> 1]];
        int v1 = lut[index[(x + 1) >> 1]];
        dst[x]     = (v0 >= 0 && v0 <= max) ? v0 : src[x];
        dst[x + 1] = (v1 >= 0 && v1 <= max) ? v1 : src[x + 1];
    }
    if (x < width) {
        int v = lut[index[x >> 1]];
        dst[x] = (v >= 0 && v <= max) ? v : src[x];
    }
    index += ilinesize / 2;
    src += slinesize / 2;
    dst += dlinesize / 2;
}
}
