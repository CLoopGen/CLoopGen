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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    int acc = 0;
    for (i = 0; i < h; i++) {
        acc += A + B + C + D;

        dst[0] = ((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + acc + 28) >> 6);
        dst[1] = ((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + acc + 28) >> 6);
        dst[2] = ((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + acc + 28) >> 6);
        dst[3] = ((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + acc + 28) >> 6);

        src += stride;
        dst += stride;
    }
}
