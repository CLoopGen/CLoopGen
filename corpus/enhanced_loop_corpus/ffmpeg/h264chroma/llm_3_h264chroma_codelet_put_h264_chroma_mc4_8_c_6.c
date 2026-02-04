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
    ptrdiff_t base_src = i * stride;
    ptrdiff_t base_dst = i * stride;
    const uint8_t* s = src;
    uint8_t* d = dst;
    d[base_dst + 0] = ((((A * s[base_src + 0] + B * s[base_src + 1] + C * s[base_src + stride + 0] + D * s[base_src + stride + 1])) + 32) >> 6);
    d[base_dst + 1] = ((((A * s[base_src + 1] + B * s[base_src + 2] + C * s[base_src + stride + 1] + D * s[base_src + stride + 2])) + 32) >> 6);
    d[base_dst + 2] = ((((A * s[base_src + 2] + B * s[base_src + 3] + C * s[base_src + stride + 2] + D * s[base_src + stride + 3])) + 32) >> 6);
    d[base_dst + 3] = ((((A * s[base_src + 3] + B * s[base_src + 4] + C * s[base_src + stride + 3] + D * s[base_src + stride + 4])) + 32) >> 6);
}
}
