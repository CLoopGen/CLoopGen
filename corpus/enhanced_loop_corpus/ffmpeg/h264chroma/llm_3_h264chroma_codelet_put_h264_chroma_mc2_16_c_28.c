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
    ptrdiff_t current_dst = i * stride;
    ptrdiff_t current_src = i * stride;
    dst[current_dst] = ((((A * src[current_src] + E * src[current_src + step])) + 32) >> 6);
    dst[current_dst + 1] = ((((A * src[current_src + 1] + E * src[current_src + step + 1])) + 32) >> 6);
}
}
