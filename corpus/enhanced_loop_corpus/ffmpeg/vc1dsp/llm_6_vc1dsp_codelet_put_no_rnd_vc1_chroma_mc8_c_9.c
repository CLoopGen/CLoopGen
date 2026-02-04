#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t temp[8];
        temp[0] = ((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + 28) >> 6);
        temp[1] = ((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + 28) >> 6);
        temp[2] = ((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + 28) >> 6);
        temp[3] = ((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + 28) >> 6);
        temp[4] = ((A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5] + 28) >> 6);
        temp[5] = ((A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6] + 28) >> 6);
        temp[6] = ((A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7] + 28) >> 6);
        temp[7] = ((A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8] + 28) >> 6);
        for (int j = 0; j < 8; j++) {
            dst[j] = temp[j];
        }
        dst += stride;
        src += stride;
    }
}
