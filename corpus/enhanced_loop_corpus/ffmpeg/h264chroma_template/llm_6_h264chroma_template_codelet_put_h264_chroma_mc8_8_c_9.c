#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
    uint8_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7], temp8 = src[8];
    uint8_t tstride0 = src[stride + 0], tstride1 = src[stride + 1], tstride2 = src[stride + 2];
    uint8_t tstride3 = src[stride + 3], tstride4 = src[stride + 4], tstride5 = src[stride + 5];
    uint8_t tstride6 = src[stride + 6], tstride7 = src[stride + 7], tstride8 = src[stride + 8];

    dst[0] = ((((A * temp0 + B * temp1 + C * tstride0 + D * tstride1)) + 32) >> 6);
    dst[1] = ((((A * temp1 + B * temp2 + C * tstride1 + D * tstride2)) + 32) >> 6);
    dst[2] = ((((A * temp2 + B * temp3 + C * tstride2 + D * tstride3)) + 32) >> 6);
    dst[3] = ((((A * temp3 + B * temp4 + C * tstride3 + D * tstride4)) + 32) >> 6);
    dst[4] = ((((A * temp4 + B * temp5 + C * tstride4 + D * tstride5)) + 32) >> 6);
    dst[5] = ((((A * temp5 + B * temp6 + C * tstride5 + D * tstride6)) + 32) >> 6);
    dst[6] = ((((A * temp6 + B * temp7 + C * tstride6 + D * tstride7)) + 32) >> 6);
    dst[7] = ((((A * temp7 + B * temp8 + C * tstride7 + D * tstride8)) + 32) >> 6);

    dst += stride;
    src += stride;
}
}
