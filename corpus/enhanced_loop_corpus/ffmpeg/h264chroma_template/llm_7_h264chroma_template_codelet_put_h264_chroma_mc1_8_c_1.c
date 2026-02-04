#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t local_stride = stride;
    int local_h = h;
    uint8_t* local_dst = dst;
    uint8_t* local_src = src;
    int local_A = A;
    int local_E = E;
    int local_step = step;
    uint8_t temp_buffer[2] = {0}; 
    for (i = 0; i < local_h; i++) {
        temp_buffer[0] = local_src[0];
        temp_buffer[1] = local_src[local_step];
        int val = ((local_A * temp_buffer[0] + local_E * temp_buffer[1] + 32) >> 6);
        local_dst[0] = val;
        temp_buffer[0] = local_dst[0]; 
        local_dst += local_stride;
        local_src += local_stride;
    }
}
