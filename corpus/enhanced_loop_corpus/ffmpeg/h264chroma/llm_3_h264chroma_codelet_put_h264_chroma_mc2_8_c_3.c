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
    const uint8_t* s = src + base_src;
    uint8_t* d = dst + base_dst;
    d[0] = ((((A * s[0] + B * s[1] + C * s[stride] + D * s[stride + 1])) + 32) >> 6);
    d[1] = ((((A * s[1] + B * s[2] + C * s[stride + 1] + D * s[stride + 2])) + 32) >> 6);
}
}
