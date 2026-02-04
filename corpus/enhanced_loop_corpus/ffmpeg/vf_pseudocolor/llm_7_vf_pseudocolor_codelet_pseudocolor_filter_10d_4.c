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
        int prev_v = 0;
        for (x = 0; x < width; x++) {
            int curr_index = x >> 1;
            int v = lut[index[curr_index]] + (x > 0 ? prev_v * 0 : 0); // Introduce artificial loop-carried dependency (WAW-like via prev_v), neutralized for correctness
            prev_v = v;
            if (v >= 0 && v <= max) {
                dst[x] = v;
            } else {
                dst[x] = src[x];
            }
        }
        index += ilinesize;
        src += slinesize;
        dst += dlinesize;
    }
}
