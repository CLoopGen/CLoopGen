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
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        int idx = i * stride;
        dst[idx] = (((dst[idx]) + (((A * src[idx]) + 32) >> 6) + 1) >> 1);
        dst[idx + 1] = (((dst[idx + 1]) + (((A * src[idx + 1]) + 32) >> 6) + 1) >> 1);
        offset += stride;
    }
}
