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
        local_dst[offset + 0] = ((((A * local_src[offset + 0] + E * local_src[offset + step + 0])) + 32) >> 6);
        local_dst[offset + 1] = ((((A * local_src[offset + 1] + E * local_src[offset + step + 1])) + 32) >> 6);
        local_dst[offset + 2] = ((((A * local_src[offset + 2] + E * local_src[offset + step + 2])) + 32) >> 6);
        local_dst[offset + 3] = ((((A * local_src[offset + 3] + E * local_src[offset + step + 3])) + 32) >> 6);
    }
}
