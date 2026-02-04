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
    for (int j = 0; j < 8; j++) {
        dst[base_dst + j] = (((dst[base_dst + j]) + ((((A * src[base_src + j] + E * src[base_src + step + j])) + 32) >> 6) + 1) >> 1);
    }
}
}
