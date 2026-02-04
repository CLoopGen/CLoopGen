#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int h;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int offset = (1 << (SHIFT - 1));
    int val0 = src[-2] + src[3] - 5*(src[-1] + src[2]) + src[0]*C1 + src[1]*C2 + offset;
    int val1 = src[-1] + src[4] - 5*(src[0] + src[3]) + src[1]*C1 + src[2]*C2 + offset;
    int val2 = src[0] + src[5] - 5*(src[1] + src[4]) + src[2]*C1 + src[3]*C2 + offset;
    int val3 = src[1] + src[6] - 5*(src[2] + src[5]) + src[3]*C1 + src[4]*C2 + offset;
    int val4 = src[2] + src[7] - 5*(src[3] + src[6]) + src[4]*C1 + src[5]*C2 + offset;
    int val5 = src[3] + src[8] - 5*(src[4] + src[7]) + src[5]*C1 + src[6]*C2 + offset;
    int val6 = src[4] + src[9] - 5*(src[5] + src[8]) + src[6]*C1 + src[7]*C2 + offset;
    int val7 = src[5] + src[10] - 5*(src[6] + src[9]) + src[7]*C1 + src[8]*C2 + offset;

    uint8_t idx0 = val0 >> SHIFT;
    uint8_t idx1 = val1 >> SHIFT;
    uint8_t idx2 = val2 >> SHIFT;
    uint8_t idx3 = val3 >> SHIFT;
    uint8_t idx4 = val4 >> SHIFT;
    uint8_t idx5 = val5 >> SHIFT;
    uint8_t idx6 = val6 >> SHIFT;
    uint8_t idx7 = val7 >> SHIFT;

    uint8_t cm0 = cm[idx0], cm1 = cm[idx1], cm2 = cm[idx2], cm3 = cm[idx3];
    uint8_t cm4 = cm[idx4], cm5 = cm[idx5], cm6 = cm[idx6], cm7 = cm[idx7];

    dst[0] = ((dst[0] + cm0 + 1) >> 1);
    dst[1] = ((dst[1] + cm1 + 1) >> 1);
    dst[2] = ((dst[2] + cm2 + 1) >> 1);
    dst[3] = ((dst[3] + cm3 + 1) >> 1);
    dst[4] = ((dst[4] + cm4 + 1) >> 1);
    dst[5] = ((dst[5] + cm5 + 1) >> 1);
    dst[6] = ((dst[6] + cm6 + 1) >> 1);
    dst[7] = ((dst[7] + cm7 + 1) >> 1);

    dst += dstStride;
    src += srcStride;
}
}
