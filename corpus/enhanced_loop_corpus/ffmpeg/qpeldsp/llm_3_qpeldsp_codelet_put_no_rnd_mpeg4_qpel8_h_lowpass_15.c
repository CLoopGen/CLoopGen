#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp_src[9];
    for (int k = 0; k < 9; k++) {
        temp_src[k] = src[k];
    }
    dst[0] = cm[(((temp_src[0] + temp_src[1]) * 20 - (temp_src[0] + temp_src[2]) * 6 + (temp_src[1] + temp_src[3]) * 3 - (temp_src[2] + temp_src[4])) + 15) >> 5];
    dst[1] = cm[(((temp_src[1] + temp_src[2]) * 20 - (temp_src[0] + temp_src[3]) * 6 + (temp_src[0] + temp_src[4]) * 3 - (temp_src[1] + temp_src[5])) + 15) >> 5];
    dst[2] = cm[(((temp_src[2] + temp_src[3]) * 20 - (temp_src[1] + temp_src[4]) * 6 + (temp_src[0] + temp_src[5]) * 3 - (temp_src[0] + temp_src[6])) + 15) >> 5];
    dst[3] = cm[(((temp_src[3] + temp_src[4]) * 20 - (temp_src[2] + temp_src[5]) * 6 + (temp_src[1] + temp_src[6]) * 3 - (temp_src[0] + temp_src[7])) + 15) >> 5];
    dst[4] = cm[(((temp_src[4] + temp_src[5]) * 20 - (temp_src[3] + temp_src[6]) * 6 + (temp_src[2] + temp_src[7]) * 3 - (temp_src[1] + temp_src[8])) + 15) >> 5];
    dst[5] = cm[(((temp_src[5] + temp_src[6]) * 20 - (temp_src[4] + temp_src[7]) * 6 + (temp_src[3] + temp_src[8]) * 3 - (temp_src[2] + temp_src[8])) + 15) >> 5];
    dst[6] = cm[(((temp_src[6] + temp_src[7]) * 20 - (temp_src[5] + temp_src[8]) * 6 + (temp_src[4] + temp_src[8]) * 3 - (temp_src[3] + temp_src[7])) + 15) >> 5];
    dst[7] = cm[(((temp_src[7] + temp_src[8]) * 20 - (temp_src[6] + temp_src[8]) * 6 + (temp_src[5] + temp_src[7]) * 3 - (temp_src[4] + temp_src[6])) + 15) >> 5];
    dst += dstStride;
    src += srcStride;
}
}
