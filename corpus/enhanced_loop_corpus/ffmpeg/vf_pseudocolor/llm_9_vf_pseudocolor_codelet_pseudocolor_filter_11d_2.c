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
    int base_iy = (y >> 1) * ilinesize;
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (x = 0; x < width; x += 4) {
        int ix0 = base_iy + (x >> 1);
        int ix1 = base_iy + ((x+1) >> 1);
        int ix2 = base_iy + ((x+2) >> 1);
        int ix3 = base_iy + ((x+3) >> 1);

        int v0 = (int)(lut[index[ix0]]);
        int v1 = (int)(lut[index[ix1]]);
        int v2 = (int)(lut[index[ix2]]);
        int v3 = (int)(lut[index[ix3]]);

        dst_row[x+0] = (v0 >= 0 && v0 <= max) ? v0 : src_row[x+0];
        dst_row[x+1] = (v1 >= 0 && v1 <= max) ? v1 : src_row[x+1];
        dst_row[x+2] = (v2 >= 0 && v2 <= max) ? v2 : src_row[x+2];
        dst_row[x+3] = (v3 >= 0 && v3 <= max) ? v3 : src_row[x+3];
    }
    src += slinesize;
    dst += dlinesize;
}
}
