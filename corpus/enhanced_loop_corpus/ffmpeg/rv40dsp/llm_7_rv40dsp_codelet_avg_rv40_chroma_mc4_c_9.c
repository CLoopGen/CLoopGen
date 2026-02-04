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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    int prev_result = 0;
    for (i = 0; i < h; i++) {
        int val0 = (A * local_src[0] + B * local_src[1] + C * local_src[stride + 0] + D * local_src[stride + 1] + bias + prev_result) >> 6;
        int val1 = (A * local_src[1] + B * local_src[2] + C * local_src[stride + 1] + D * local_src[stride + 2] + bias) >> 6;
        int val2 = (A * local_src[2] + B * local_src[3] + C * local_src[stride + 2] + D * local_src[stride + 3] + bias) >> 6;
        int val3 = (A * local_src[3] + B * local_src[4] + C * local_src[stride + 3] + D * local_src[stride + 4] + bias) >> 6;

        local_dst[0] = ((local_dst[0] + val0 + 1) >> 1);
        local_dst[1] = ((local_dst[1] + val1 + 1) >> 1);
        local_dst[2] = ((local_dst[2] + val2 + 1) >> 1);
        local_dst[3] = ((local_dst[3] + val3 + 1) >> 1);

        prev_result = val0; // Introduce loop-carried dependency (RAW): current iteration depends on prior
        local_dst += stride;
        local_src += stride;
    }
}
