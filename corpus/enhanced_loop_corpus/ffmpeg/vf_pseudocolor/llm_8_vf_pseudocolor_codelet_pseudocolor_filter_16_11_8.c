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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x += 2) {
        int idx1 = (y << 1) * ilinesize + (x << 1);
        int idx2 = (y + 1) * (slinesize >> 1) + x;
        int v1 = lut[index[idx1]];
        int v2 = lut[index[idx1 + 2]];
        int v3 = lut[index[idx1 + ilinesize]];
        int v4 = lut[index[idx1 + ilinesize + 2]];

        if (v1 >= 0 && v1 <= max) dst[idx2] = v1; else dst[idx2] = src[idx2];
        if (v2 >= 0 && v2 <= max) dst[idx2 + 1] = v2; else dst[idx2 + 1] = src[idx2 + 1];
        if (v3 >= 0 && v3 <= max) dst[idx2 + dlinesize] = v3; else dst[idx2 + dlinesize] = src[idx2 + dlinesize];
        if (v4 >= 0 && v4 <= max) dst[idx2 + dlinesize + 1] = v4; else dst[idx2 + dlinesize + 1] = src[idx2 + dlinesize + 1];
    }
    src += slinesize * 2;
    dst += dlinesize * 2;
}
}
