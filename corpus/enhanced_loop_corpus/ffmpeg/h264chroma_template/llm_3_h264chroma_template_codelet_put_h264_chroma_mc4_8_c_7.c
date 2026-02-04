#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t base_src = i * stride;
    ptrdiff_t base_dst = i * stride;
    uint8_t temp[4];
    temp[0] = src[base_src + 0];
    temp[1] = src[base_src + 1];
    temp[2] = src[base_src + 2];
    temp[3] = src[base_src + 3];
    dst[base_dst + 0] = ((((A * temp[0] + E * src[base_src + step + 0])) + 32) >> 6);
    dst[base_dst + 1] = ((((A * temp[1] + E * src[base_src + step + 1])) + 32) >> 6);
    dst[base_dst + 2] = ((((A * temp[2] + E * src[base_src + step + 2])) + 32) >> 6);
    dst[base_dst + 3] = ((((A * temp[3] + E * src[base_src + step + 3])) + 32) >> 6);
}
}
