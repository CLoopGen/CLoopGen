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
for (int outer = 0; outer < h; outer++) {
    for (int inner = 0; inner < 16; inner++) {
        int offset = (src[inner] + src[inner + 1]) * 20;
        int term2 = (inner >= 1) ? (src[inner - 1] + src[inner + 2]) * 6 : (src[0] + src[2]) * 6;
        int term3 = (inner >= 2) ? (src[inner - 2] + src[inner + 3]) * 3 : ((inner == 1) ? (src[0] + src[4]) * 3 : (src[1] + src[3]) * 3);
        int term4 = (inner >= 3) ? (src[inner - 3] + src[inner + 4]) : ((inner == 2) ? (src[0] + src[7]) : ((inner == 1) ? (src[1] + src[5]) : (src[2] + src[4])));
        if (inner == 13) term4 = src[10] + src[16];
        if (inner == 14) term4 = src[11] + src[15];
        if (inner == 15) term4 = src[12] + src[14];

        int index = ((offset - term2 + term3 - term4) + 16) >> 5;
        dst[inner] = ((dst[inner] + cm[index] + 1) >> 1);
    }
    dst += dstStride;
    src += srcStride;
}
}
