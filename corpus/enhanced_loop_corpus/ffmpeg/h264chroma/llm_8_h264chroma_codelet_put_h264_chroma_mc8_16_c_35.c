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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    ptrdiff_t dst_offset = 0, src_offset = 0;
    for (i = 0; i < h; i++) {
        for (j = 0; j < 8; j++) {
            dst[dst_offset + j] = (((A * src[src_offset + j]) + 32) >> 6);
        }
        dst_offset += stride;
        src_offset += stride;
    }
}
