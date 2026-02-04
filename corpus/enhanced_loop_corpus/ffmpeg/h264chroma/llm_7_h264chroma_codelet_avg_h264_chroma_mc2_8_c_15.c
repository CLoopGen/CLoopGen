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
    ptrdiff_t s = stride;
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    int acc_A = 0, acc_B = 0, acc_C = 0, acc_D = 0;

    for (i = 0; i < h; i++) {
        acc_A += A * local_src[0];
        acc_B += B * local_src[1];
        acc_C += C * local_src[s + 0];
        acc_D += D * local_src[s + 1];

        int val0 = ((acc_A + acc_B + acc_C + acc_D + 32) >> 6);
        local_dst[0] = ((local_dst[0] + val0 + 1) >> 1);

        acc_A += A * local_src[1];
        acc_B += B * local_src[2];
        acc_C += C * local_src[s + 1];
        acc_D += D * local_src[s + 2];

        int val1 = ((acc_A + acc_B + acc_C + acc_D + 32) >> 6);
        local_dst[1] = ((local_dst[1] + val1 + 1) >> 1);

        local_dst += s;
        local_src += s;
    }
}
