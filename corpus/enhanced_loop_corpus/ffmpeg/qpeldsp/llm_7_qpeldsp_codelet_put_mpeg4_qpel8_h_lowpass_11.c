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
    uint8_t s[9];
    for (int j = 0; j < 9; j++) {
        s[j] = src[j];
    }

    dst[0] = cm[(((s[0] + s[1]) * 20 - (s[0] + s[2]) * 6 + (s[1] + s[3]) * 3 - (s[2] + s[4])) + 16) >> 5];
    dst[1] = cm[(((s[1] + s[2]) * 20 - (s[0] + s[3]) * 6 + (s[0] + s[4]) * 3 - (s[1] + s[5])) + 16) >> 5];
    dst[2] = cm[(((s[2] + s[3]) * 20 - (s[1] + s[4]) * 6 + (s[0] + s[5]) * 3 - (s[0] + s[6])) + 16) >> 5];
    dst[3] = cm[(((s[3] + s[4]) * 20 - (s[2] + s[5]) * 6 + (s[1] + s[6]) * 3 - (s[0] + s[7])) + 16) >> 5];
    dst[4] = cm[(((s[4] + s[5]) * 20 - (s[3] + s[6]) * 6 + (s[2] + s[7]) * 3 - (s[1] + s[8])) + 16) >> 5];
    dst[5] = cm[(((s[5] + s[6]) * 20 - (s[4] + s[7]) * 6 + (s[3] + s[8]) * 3 - (s[2] + s[8])) + 16) >> 5];
    dst[6] = cm[(((s[6] + s[7]) * 20 - (s[5] + s[8]) * 6 + (s[4] + s[8]) * 3 - (s[3] + s[7])) + 16) >> 5];
    dst[7] = cm[(((s[7] + s[8]) * 20 - (s[6] + s[8]) * 6 + (s[5] + s[7]) * 3 - (s[4] + s[6])) + 16) >> 5];

    dst += dstStride;
    src += srcStride;
}
}
