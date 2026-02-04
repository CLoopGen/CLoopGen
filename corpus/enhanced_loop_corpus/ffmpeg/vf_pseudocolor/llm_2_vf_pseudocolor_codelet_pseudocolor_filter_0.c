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
    for (x = 0; x < width; x += 2) {
        int v1 = lut[index[x]];
        int v2 = (x + 1 < width) ? lut[index[x + 1]] : v1;
        if (v1 >= 0 && v1 <= max) {
            dst[x] = v1;
        } else {
            dst[x] = src[x];
        }
        if (x + 1 < width) {
            if (v2 >= 0 && v2 <= max) {
                dst[x + 1] = v2;
            } else {
                dst[x + 1] = src[x + 1];
            }
        }
    }
    index += ilinesize;
    src += slinesize;
    dst += dlinesize;
}
}
