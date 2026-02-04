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
    ptrdiff_t read_idx1 = i * stride;
    ptrdiff_t read_idx2 = (h - 1 - i) * stride; // Reverse access pattern on src
    dst[i * stride] = ((((A * src[read_idx1] + E * src[read_idx2 + step])) + 32) >> 6);
}
}
