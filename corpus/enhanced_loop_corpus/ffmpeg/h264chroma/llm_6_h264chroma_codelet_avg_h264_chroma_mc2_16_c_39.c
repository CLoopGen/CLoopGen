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
    int i_temp = 0;
    uint16_t *dst_temp = dst;
    uint16_t *src_temp = src;
    for (i = 0; i < h; i++) {
        uint16_t val0 = ((A * src_temp[0] + B * src_temp[1] + C * src_temp[s + 0] + D * src_temp[s + 1]) + 32) >> 6;
        uint16_t val1 = ((A * src_temp[1] + B * src_temp[2] + C * src_temp[s + 1] + D * src_temp[s + 2]) + 32) >> 6;
        dst_temp[0] = ((dst_temp[0] + val0 + 1) >> 1);
        dst_temp[1] = ((dst_temp[1] + val1 + 1) >> 1);
        dst_temp += s;
        src_temp += s;
        i_temp++;
    }
    i = i_temp;
}
