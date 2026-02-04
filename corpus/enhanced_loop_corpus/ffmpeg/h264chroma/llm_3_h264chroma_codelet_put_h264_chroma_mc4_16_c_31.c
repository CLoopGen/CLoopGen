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
    ptrdiff_t idx0 = i * stride;
    ptrdiff_t idx1 = i * stride + step;
    dst[idx0 + 0] = ((((A * src[idx0 + 0] + E * src[idx1 + 0])) + 32) >> 6);
    dst[idx0 + 1] = ((((A * src[idx0 + 1] + E * src[idx1 + 1])) + 32) >> 6);
    dst[idx0 + 2] = ((((A * src[idx0 + 2] + E * src[idx1 + 2])) + 32) >> 6);
    dst[idx0 + 3] = ((((A * src[idx0 + 3] + E * src[idx1 + 3])) + 32) >> 6);
}
}
