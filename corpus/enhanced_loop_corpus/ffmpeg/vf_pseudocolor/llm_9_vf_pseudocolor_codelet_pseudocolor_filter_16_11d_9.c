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
    for (x = 0; x < width; x++) {
        int base_iy = (y >> 1) * ilinesize;
        int ix = (x >> 1);

        int v = lut[index[base_iy + ix]];
        int clamped_v = (v >= 0 && v <= max) ? v : src[x];
        dst[x] = clamped_v;

        if (y + 1 < height) {
            int v_next_row = lut[index[base_iy + ix]];
            int clamped_v_next = (v_next_row >= 0 && v_next_row <= max) ? v_next_row : src[slinesize + x];
            dst[dlinesize + x] = clamped_v_next;
        }
    }
    src += 2 * slinesize;
    dst += 2 * dlinesize;
}
}
