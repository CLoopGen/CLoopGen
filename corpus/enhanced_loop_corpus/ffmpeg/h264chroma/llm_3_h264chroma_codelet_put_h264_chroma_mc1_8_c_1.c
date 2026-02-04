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
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t base_src = i * stride;
    ptrdiff_t base_dst = i * stride;
    // Unroll by 2 for consecutive access pattern where possible
    dst[base_dst] = ((((A * src[base_src] + E * src[base_src + step])) + 32) >> 6);
    if (i + 1 < h) {
        ptrdiff_t next_src = (i + 1) * stride;
        ptrdiff_t next_dst = (i + 1) * stride;
        dst[next_dst] = ((((A * src[next_src] + E * src[next_src + step])) + 32) >> 6);
        i++;
    }
}
}
