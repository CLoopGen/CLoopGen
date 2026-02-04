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
    uint16_t *dst_temp = dst;
    uint16_t *src_temp = src;
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        dst_temp[offset] = (((dst_temp[offset]) + ((((A * src_temp[offset])) + 32) >> 6) + 1) >> 1);
        offset += stride;
    }
}
