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
    dst[0] = ((((A * src[base_src] + E * src[base_src + step])) + 32) >> 6);
    dst[1] = ((((A * src[base_src + 1] + E * src[base_src + step + 1])) + 32) >> 6);
    dst += stride;
}
}
