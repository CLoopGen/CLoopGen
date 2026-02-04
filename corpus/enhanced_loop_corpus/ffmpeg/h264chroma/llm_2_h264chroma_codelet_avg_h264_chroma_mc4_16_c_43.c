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
for (i = 0; i < h; i++) {
    ptrdiff_t base_dst = i * stride;
    ptrdiff_t base_src = i * stride;
    dst[base_dst + 0] = (((dst[base_dst + 0]) + ((((A * src[base_src + 0] + E * src[base_src + step + 0])) + 32) >> 6) + 1) >> 1);
    dst[base_dst + 1] = (((dst[base_dst + 1]) + ((((A * src[base_src + 1] + E * src[base_src + step + 1])) + 32) >> 6) + 1) >> 1);
    dst[base_dst + 2] = (((dst[base_dst + 2]) + ((((A * src[base_src + 2] + E * src[base_src + step + 2])) + 32) >> 6) + 1) >> 1);
    dst[base_dst + 3] = (((dst[base_dst + 3]) + ((((A * src[base_src + 3] + E * src[base_src + step + 3])) + 32) >> 6) + 1) >> 1);
}
}
