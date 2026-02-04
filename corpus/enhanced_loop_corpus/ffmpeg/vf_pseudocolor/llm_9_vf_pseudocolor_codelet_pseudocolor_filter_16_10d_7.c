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
    for (x = 0; x < width; x += 4) {
        // Unroll loop by factor of 4 with reduced conditional checks using arithmetic
        int idx_base = x >> 1;
        int cond0 = lut[idx_base + 0];
        int cond1 = lut[idx_base + (x+1 < width ? 0 : 0)]; // Avoid out-of-bounds, simplified for stride
        int cond2 = lut[idx_base + (x+2 < width ? 1 : 0)];
        int cond3 = lut[idx_base + (x+3 < width ? 1 : 0)];

        dst[x + 0] = (cond0 >= 0 && cond0 <= max) ? cond0 : src[x + 0];
        if (x + 1 < width) dst[x + 1] = (cond0 >= 0 && cond0 <= max) ? cond0 : src[x + 1];
        if (x + 2 < width) dst[x + 2] = (cond2 >= 0 && cond2 <= max) ? cond2 : src[x + 2];
        if (x + 3 < width) dst[x + 3] = (cond3 >= 0 && cond3 <= max) ? cond3 : src[x + 3];
    }
    index += ilinesize / 2;
    src += slinesize / 2;
    dst += dlinesize / 2;
}
}
