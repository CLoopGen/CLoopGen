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
        acc_A += A; // Introduce artificial loop-carried dependency (WAW on acc_A)
        acc_B += B;
        acc_C += C;
        acc_D += D;

        int val0 = local_src[0], val1 = local_src[1];
        int valS0 = local_src[s + 0], valS1 = local_src[s + 1];

        local_dst[0] = (((acc_A * val0 + acc_B * val1 + acc_C * valS0 + acc_D * valS1) + 32) >> 6);

        int val1_next = local_src[2];
        int valS2 = local_src[s + 2];
        local_dst[1] = (((acc_A * val1 + acc_B * val1_next + acc_C * valS1 + acc_D * valS2) + 32) >> 6);

        local_dst += s;
        local_src += s;
    }

    dst = local_dst; 
    src = local_src;
}
