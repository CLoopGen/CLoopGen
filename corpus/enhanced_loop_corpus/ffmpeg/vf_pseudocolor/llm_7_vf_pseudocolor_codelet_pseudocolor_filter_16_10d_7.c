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
    int prev_x = -1;
    int carried_value = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int offset = (prev_x >= 0) ? (carried_value & 1) : 0;
            int effective_idx = (x + offset) >> 1;
            int v = lut[index[effective_idx]];
            if (v >= 0 && v <= max) {
                dst[x] = v;
            } else {
                dst[x] = src[x];
            }
            carried_value = v;
            prev_x = x;
        }
        index += ilinesize / 2;
        src += slinesize / 2;
        dst += dlinesize / 2;
    }
}
