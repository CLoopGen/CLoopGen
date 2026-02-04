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
    ptrdiff_t idx = 0;
    for (i = 0; i < h; i++) {
        ptrdiff_t base_dst = idx;
        ptrdiff_t base_src = idx;
        dst[base_dst + 0] = (((A * src[base_src + 0]) + 32) >> 6);
        dst[base_dst + 1] = (((A * src[base_src + 1]) + 32) >> 6);
        dst[base_dst + 2] = (((A * src[base_src + 2]) + 32) >> 6);
        dst[base_dst + 3] = (((A * src[base_src + 3]) + 32) >> 6);
        idx += stride;
    }
}
