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
    int local_h = h;
    uint8_t* local_dst = dst;
    uint8_t* local_src = src;
    int temp_A = A, temp_B = B, temp_C = C, temp_D = D;
    for (i = 0; i < local_h; i++) {
        int pixel_sum = temp_A * local_src[0] + temp_B * local_src[1] +
                        temp_C * local_src[s + 0] + temp_D * local_src[s + 1];
        int filtered = ((local_dst[0]) + ((pixel_sum + 32) >> 6) + 1) >> 1;
        local_dst[0] = (uint8_t)filtered;
        local_dst += s;
        local_src += s;
    }
}
