#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t base_dst = i * stride;
    ptrdiff_t base_src = (h - 1 - i) * stride; // Reverse row traversal in src
    dst[base_dst] = (((dst[base_dst]) + ((((A * src[base_src] + B * src[base_src + 1] + C * src[base_src + stride] + D * src[base_src + stride + 1])) + 32) >> 6) + 1) >> 1);
}
}
