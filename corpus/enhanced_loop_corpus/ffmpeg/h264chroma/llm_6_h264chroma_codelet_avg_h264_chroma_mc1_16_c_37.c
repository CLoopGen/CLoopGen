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
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t temp_stride = stride;
    int local_h = h;
    uint16_t* local_dst = dst;
    uint16_t* local_src = src;
    int local_A = A;
    int local_E = E;
    int local_step = step;

    for (i = 0; i < local_h; i++) {
        int temp_val = ((local_A * local_src[0] + local_E * local_src[local_step + 0]) + 32) >> 6;
        local_dst[0] = ((local_dst[0] + temp_val + 1) >> 1);
        local_dst += temp_stride;
        local_src += temp_stride;
    }
}
