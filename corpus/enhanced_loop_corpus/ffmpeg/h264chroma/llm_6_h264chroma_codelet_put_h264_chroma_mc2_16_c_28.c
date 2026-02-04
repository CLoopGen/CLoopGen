#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_A = A;
    int temp_E = E;
    ptrdiff_t local_stride = stride;
    ptrdiff_t local_step = step;
    uint16_t *local_dst = dst;
    uint16_t *local_src = src;
    for (i = 0; i < h; i++) {
        int val0 = temp_A * local_src[0] + temp_E * local_src[local_step + 0];
        int val1 = temp_A * local_src[1] + temp_E * local_src[local_step + 1];
        local_dst[0] = ((val0 + 32) >> 6);
        local_dst[1] = ((val1 + 32) >> 6);
        local_dst += local_stride;
        local_src += local_stride;
    }
}
