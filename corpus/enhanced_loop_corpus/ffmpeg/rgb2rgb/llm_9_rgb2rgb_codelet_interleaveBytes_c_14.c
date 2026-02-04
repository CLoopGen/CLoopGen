#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern uint8_t *dest;
extern int width;
extern int height;
extern int src1Stride;
extern int src2Stride;
extern int dstStride;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < height; h += 2) {
    int w;
    for (w = 0; w < width; w++) {
        uint8_t val1 = src1[w];
        uint8_t val2 = src2[w];
        dest[2 * w + 0] = val1;
        dest[2 * w + 1] = val2;
        if (h + 1 < height) {
            uint8_t* next_dest = dest + dstStride;
            uint8_t* next_src1 = src1 + src1Stride;
            uint8_t* next_src2 = src2 + src2Stride;
            next_dest[2 * w + 0] = next_src1[w];
            next_dest[2 * w + 1] = next_src2[w];
        }
    }
    dest += 2 * dstStride;
    src1 += 2 * src1Stride;
    src2 += 2 * src2Stride;
}
}
