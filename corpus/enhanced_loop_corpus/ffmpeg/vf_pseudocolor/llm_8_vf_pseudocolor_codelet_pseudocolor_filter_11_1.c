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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x += 2) {
        int v1 = lut[index[(y << 1) * ilinesize + (x << 1)]];
        int v2 = lut[index[((y << 1) + 1) * ilinesize + (x << 1)]];
        int v3 = lut[index[(y << 1) * ilinesize + ((x << 1) + 1)]];
        int v4 = lut[index[((y << 1) + 1) * ilinesize + ((x << 1) + 1)]];
        int avg = (v1 + v2 + v3 + v4) >> 2;
        dst[x] = (avg >= 0 && avg <= max) ? avg : src[x];
        if (x + 1 < width) {
            dst[x + 1] = src[x + 1];
        }
    }
    if (y + 1 < height) {
        src += slinesize * 2;
        dst += dlinesize * 2;
    } else {
        src += slinesize;
        dst += dlinesize;
    }
}
}
