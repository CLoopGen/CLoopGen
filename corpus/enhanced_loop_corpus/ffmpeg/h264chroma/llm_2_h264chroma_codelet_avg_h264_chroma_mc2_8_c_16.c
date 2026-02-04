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
        ptrdiff_t offset = i * stride;
        dst[offset] = (((dst[offset]) + ((((A * src[offset] + E * src[offset + step])) + 32) >> 6) + 1) >> 1);
        dst[offset + 1] = (((dst[offset + 1]) + ((((A * src[offset + 1] + E * src[offset + step + 1])) + 32) >> 6) + 1) >> 1);
    }
}
