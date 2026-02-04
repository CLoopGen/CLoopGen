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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t s = stride;
    int local_h = h;
    uint8_t* local_dst = dst;
    uint8_t* local_src = src;
    int local_A = A;
    for (i = 0; i < local_h; i++) {
        uint8_t temp0 = (((local_A * local_src[0]) + 32) >> 6);
        uint8_t temp1 = (((local_A * local_src[1]) + 32) >> 6);
        uint8_t temp2 = (((local_A * local_src[2]) + 32) >> 6);
        uint8_t temp3 = (((local_A * local_src[3]) + 32) >> 6);
        uint8_t temp4 = (((local_A * local_src[4]) + 32) >> 6);
        uint8_t temp5 = (((local_A * local_src[5]) + 32) >> 6);
        uint8_t temp6 = (((local_A * local_src[6]) + 32) >> 6);
        uint8_t temp7 = (((local_A * local_src[7]) + 32) >> 6);
        local_dst[0] = temp0;
        local_dst[1] = temp1;
        local_dst[2] = temp2;
        local_dst[3] = temp3;
        local_dst[4] = temp4;
        local_dst[5] = temp5;
        local_dst[6] = temp6;
        local_dst[7] = temp7;
        local_dst += s;
        local_src += s;
    }
}
