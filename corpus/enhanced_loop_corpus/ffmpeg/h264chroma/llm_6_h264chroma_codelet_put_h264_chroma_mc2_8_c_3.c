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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    ptrdiff_t s = stride;
    int i_val;
    for (i = 0; i < h; i++) {
        i_val = i;
        local_dst[0] = ((((A * local_src[0] + B * local_src[1] + C * local_src[s + 0] + D * local_src[s + 1])) + 32) >> 6);
        local_dst[1] = ((((A * local_src[1] + B * local_src[2] + C * local_src[s + 1] + D * local_src[s + 2])) + 32) >> 6);
        local_dst += s;
        local_src += s;
    }
    dst = local_dst;
    src = local_src;
}
