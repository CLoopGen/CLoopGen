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
    for (x = 0; x < width; x += 2) {
        int idx = (y >> 1) * ilinesize + (x >> 1);
        int v1 = lut[index[idx]];
        int clamped_v1 = (v1 >= 0 && v1 <= max) ? v1 : src[x];
        dst[x] = clamped_v1;

        if (x + 1 < width) {
            int v2 = lut[index[idx]];
            int clamped_v2 = (v2 >= 0 && v2 <= max) ? v2 : src[x + 1];
            dst[x + 1] = clamped_v2;
        }
    }
    src += slinesize;
    dst += dlinesize;
}
}
