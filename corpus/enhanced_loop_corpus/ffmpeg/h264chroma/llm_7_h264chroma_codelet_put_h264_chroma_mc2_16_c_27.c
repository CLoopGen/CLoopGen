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
    int i_local = 0;

    while (i_local < h) {
        int offset = i_local * s;
        dst_local[offset + 0] = (((A * src_local[offset + 0] + B * src_local[offset + 1] +
                                   C * src_local[offset + s + 0] + D * src_local[offset + s + 1]) + 32) >> 6);
        dst_local[offset + 1] = (((A * src_local[offset + 1] + B * src_local[offset + 2] +
                                   C * src_local[offset + s + 1] + D * src_local[offset + s + 2]) + 32) >> 6);
        i_local++;
    }

    i = h;
}
