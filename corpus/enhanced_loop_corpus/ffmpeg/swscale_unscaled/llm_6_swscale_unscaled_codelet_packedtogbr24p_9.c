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
    uint8_t temp0, temp1, temp2;
    for (h = 0; h < srcSliceH; h++) {
        for (x = 0; x < width; x++) {
            temp0 = src[0];
            temp1 = src[1];
            temp2 = src[2];
            dest[0][x] = temp0;
            dest[1][x] = temp1;
            dest[2][x] = temp2;
            src += inc_size;
        }
        src += srcStride - width * inc_size;
        dest[0] += dstStride[0];
        dest[1] += dstStride[1];
        dest[2] += dstStride[2];
    }
}
