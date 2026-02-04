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
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    // Introduce loop-carried dependency via accumulation in 'bias'
    // This creates a WAW and RAW dependency across iterations
    int acc = bias;

    dst[0] = (((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + acc)) >> 6);
    acc = dst[0]; // Feed output back — creates loop-carried WAW/RAR dependency

    dst[1] = (((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + acc)) >> 6);
    acc = dst[1];

    dst[2] = (((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + acc)) >> 6);
    acc = dst[2];

    dst[3] = (((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + acc)) >> 6);
    acc = dst[3];

    dst[4] = (((A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5] + acc)) >> 6);
    acc = dst[4];

    dst[5] = (((A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6] + acc)) >> 6);
    acc = dst[5];

    dst[6] = (((A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7] + acc)) >> 6);
    acc = dst[6];

    dst[7] = (((A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8] + acc)) >> 6);

    // Update bias for next iteration to carry dependency forward
    bias = dst[7] + 1; // Modify global state to create loop-carried WAW on 'bias'

    dst += stride;
    src += stride;
}
}
