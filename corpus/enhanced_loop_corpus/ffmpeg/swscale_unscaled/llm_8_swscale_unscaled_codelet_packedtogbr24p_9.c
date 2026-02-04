#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int srcStride;
extern int dstStride[];
extern int srcSliceH;
extern int inc_size;
extern int width;
extern uint8_t *dest[3];
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int h, x;
    for (h = 0; h < srcSliceH; h++) {
        uint8_t *src_offset = src + h * srcStride;
        uint8_t *dst0 = dest[0] + h * dstStride[0];
        uint8_t *dst1 = dest[1] + h * dstStride[1];
        uint8_t *dst2 = dest[2] + h * dstStride[2];
        for (x = 0; x < width; x++) {
            uint8_t val0 = src_offset[x * inc_size + 0];
            uint8_t val1 = src_offset[x * inc_size + 1];
            uint8_t val2 = src_offset[x * inc_size + 2];
            dst0[x] = val0;
            dst1[x] = val1;
            dst2[x] = val2;
        }
    }
}
