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
    uint16_t *dst_ptr = dst;
    uint16_t *src_ptr = src;
    for (i = 0; i < h; i++) {
        ptrdiff_t idx0 = 0;
        ptrdiff_t idx1 = stride;
        dst_ptr[0] = (((dst_ptr[0]) + ((((A * src_ptr[idx0] + B * src_ptr[idx0 + 1] + C * src_ptr[idx1] + D * src_ptr[idx1 + 1])) + 32) >> 6) + 1) >> 1);
        dst_ptr[1] = (((dst_ptr[1]) + ((((A * src_ptr[idx0 + 1] + B * src_ptr[idx0 + 2] + C * src_ptr[idx1 + 1] + D * src_ptr[idx1 + 2])) + 32) >> 6) + 1) >> 1);
        dst_ptr += stride;
        src_ptr += stride;
    }
}
