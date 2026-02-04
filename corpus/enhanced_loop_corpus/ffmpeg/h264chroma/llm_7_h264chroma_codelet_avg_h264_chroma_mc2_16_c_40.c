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
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *local_dst = dst;
    uint16_t *local_src = src;
    ptrdiff_t offset;
    for (i = 0; i < h; i++) {
        offset = i * stride;
        local_dst[offset] = (((local_dst[offset]) + ((((A * local_src[offset] + E * local_src[offset + step])) + 32) >> 6) + 1) >> 1);
        local_dst[offset + 1] = (((local_dst[offset + 1]) + ((((A * local_src[offset + 1] + E * local_src[offset + step + 1])) + 32) >> 6) + 1) >> 1);
    }
}
