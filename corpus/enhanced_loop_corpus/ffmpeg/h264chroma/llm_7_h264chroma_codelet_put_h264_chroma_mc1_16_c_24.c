#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t s = stride;
    uint16_t *dst_local = dst;
    uint16_t *src_local = src;
    int acc_A = A, acc_B = B, acc_C = C, acc_D = D;
    for (i = 0; i < h; i++) {
        // Introduce artificial loop-carried dependency via accumulator pattern
        acc_A = (acc_A + A) & 0x3FF;
        acc_B = (acc_B + B) & 0x3FF;
        acc_C = (acc_C + C) & 0x3FF;
        acc_D = (acc_D + D) & 0x3FF;
        dst_local[0] = ((((acc_A * src_local[0] + acc_B * src_local[1] +
                           acc_C * src_local[s + 0] + acc_D * src_local[s + 1])) + 32) >> 6);
        dst_local += s;
        src_local += s;
    }
    // Preserve semantics by ensuring final values of globals are unaffected
    dst = dst_local;
    src = src_local;
}
