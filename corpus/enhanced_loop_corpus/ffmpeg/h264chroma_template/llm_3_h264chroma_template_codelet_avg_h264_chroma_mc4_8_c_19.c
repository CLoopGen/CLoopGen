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
    ptrdiff_t base_dst = i * stride;
    ptrdiff_t base_src = i * stride;
    // Access memory with non-unit stride on src, reading every 4th element consecutively from a flattened pattern
    for (int j = 0; j < 4; j++) {
        ptrdiff_t idx = base_src + j;
        ptrdiff_t dst_idx = base_dst + j;
        dst[dst_idx] = (((dst[dst_idx]) + ((((A * src[idx] + E * src[idx + step])) + 32) >> 6) + 1) >> 1);
    }
}
}
