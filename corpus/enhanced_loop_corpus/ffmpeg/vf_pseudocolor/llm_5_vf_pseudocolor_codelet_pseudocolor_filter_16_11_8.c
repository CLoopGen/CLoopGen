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
    int skip_line = (y & 1); // Process only even-numbered source rows at full resolution
    if (skip_line) {
        for (x = 0; x < width; x++) {
            dst[x] = src[x];
        }
    } else {
        for (x = 0; x < width; x++) {
            int v = lut[index[(y << 1) * ilinesize + (x << 1)]];
            if (v > max) {
                dst[x] = src[x];
            } else if (v < 0) {
                dst[x] = src[x];
            } else {
                dst[x] = v;
            }
        }
    }
    src += slinesize;
    dst += dlinesize;
}
}
