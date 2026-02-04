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
    uint8_t *dst_local = dst;
    uint8_t *src_local = src;
    int acc_A = 0, acc_B = 0;
    for (i = 0; i < h; i++) {
        acc_A += A * src_local[0];  
        acc_B += B * src_local[1];
        int val0 = ((acc_A + acc_B + C * src_local[s + 0] + D * src_local[s + 1]) + 32) >> 6;
        int val1 = ((acc_A + acc_B + C * src_local[s + 1] + D * src_local[s + 2]) + 32) >> 6;
        dst_local[0] = ((dst_local[0] + val0 + 1) >> 1);
        dst_local[1] = ((dst_local[1] + val1 + 1) >> 1);
        dst_local += s;
        src_local += s;
    }
    dst = dst_local;
    src = src_local;
}
