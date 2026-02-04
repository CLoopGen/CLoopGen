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
    int offset = i * stride;
    dst[offset] = ((((A * src[offset] + E * src[offset + step])) + 32) >> 6);
    dst[offset + 1] = ((((A * src[offset + 1] + E * src[offset + step + 1])) + 32) >> 6);
}
}
