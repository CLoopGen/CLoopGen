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
    for (i = 0; i < h; i++) {
        uint16_t *dst_row = &dst[0];
        const uint16_t *src_row = &src[0];
        const uint16_t *src_row_next = &src[s];

        dst_row[0] = (((A * src_row[0] + B * src_row[1] + C * src_row_next[0] + D * src_row_next[1]) + 32) >> 6);
        dst_row[1] = (((A * src_row[1] + B * src_row[2] + C * src_row_next[1] + D * src_row_next[2]) + 32) >> 6);

        dst += s;
        src += s;
    }
}
