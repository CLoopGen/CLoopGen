#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    int coeff = (i % 2 == 0) ? 20 : 18;
    int offset = (i % 3 == 0) ? 0 : 1;

    tmp[0] = (src[0 + offset] + src[1 + offset]) * coeff - (src[-1 + offset] + src[2 + offset]) * 5 + (src[-2 + offset] + src[3 + offset]) + pad;
    tmp[1] = (src[1 + offset] + src[2 + offset]) * coeff - (src[0 + offset] + src[3 + offset]) * 5 + (src[-1 + offset] + src[4 + offset]) + pad;
    tmp[2] = (src[2 + offset] + src[3 + offset]) * coeff - (src[1 + offset] + src[4 + offset]) * 5 + (src[0 + offset] + src[5 + offset]) + pad;
    tmp[3] = (src[3 + offset] + src[4 + offset]) * coeff - (src[2 + offset] + src[5 + offset]) * 5 + (src[1 + offset] + src[6 + offset]) + pad;
    tmp[4] = (src[4 + offset] + src[5 + offset]) * coeff - (src[3 + offset] + src[6 + offset]) * 5 + (src[2 + offset] + src[7 + offset]) + pad;
    tmp[5] = (src[5 + offset] + src[6 + offset]) * coeff - (src[4 + offset] + src[7 + offset]) * 5 + (src[3 + offset] + src[8 + offset]) + pad;
    tmp[6] = (src[6 + offset] + src[7 + offset]) * coeff - (src[5 + offset] + src[8 + offset]) * 5 + (src[4 + offset] + src[9 + offset]) + pad;
    tmp[7] = (src[7 + offset] + src[8 + offset]) * coeff - (src[6 + offset] + src[9 + offset]) * 5 + (src[5 + offset] + src[10 + offset]) + pad;

    tmp += tmpStride;
    src += srcStride;
}
}
