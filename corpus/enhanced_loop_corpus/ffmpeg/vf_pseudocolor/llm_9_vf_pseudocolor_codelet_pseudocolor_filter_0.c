#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x += 4) {
        int v0 = lut[index[x]];
        int v1 = lut[index[x+1]];
        int v2 = lut[index[x+2]];
        int v3 = lut[index[x+3]];

        dst[x]   = (v0 >= 0 && v0 <= max) ? v0 : src[x];
        if (x+1 < width) dst[x+1] = (v1 >= 0 && v1 <= max) ? v1 : src[x+1];
        if (x+2 < width) dst[x+2] = (v2 >= 0 && v2 <= max) ? v2 : src[x+2];
        if (x+3 < width) dst[x+3] = (v3 >= 0 && v3 <= max) ? v3 : src[x+3];
    }
    index += ilinesize;
    src += slinesize;
    dst += dlinesize;
}
}
