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
        int base_iindex = (y >> 1) * ilinesize;
        int base_sindex = y * slinesize;
        int base_dindex = y * dlinesize;
        for (x = 0; x < width; x++) {
            int i_offset = base_iindex + (x >> 1);
            int s_offset = x;
            int d_offset = x;
            int v = lut[index[i_offset]];
            dst[base_dindex + d_offset] = (v >= 0 && v <= max) ? (uint8_t)v : src[base_sindex + s_offset];
        }
    }
}
