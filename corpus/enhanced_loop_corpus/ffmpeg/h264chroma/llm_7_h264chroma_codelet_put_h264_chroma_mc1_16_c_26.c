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
    uint16_t *local_dst = dst;
    uint16_t *local_src = src;
    ptrdiff_t s = stride;
    int acc = 0;
    for (i = 0; i < h; i++) {
        acc += A * local_src[0]; // Introduce loop-carried dependency (WAW on acc)
        local_dst[0] = (((acc + 32) >> 6) & 0xFFFF); // Use accumulated value, creating RAW dependency
        local_dst += s;
        local_src += s;
    }
}
