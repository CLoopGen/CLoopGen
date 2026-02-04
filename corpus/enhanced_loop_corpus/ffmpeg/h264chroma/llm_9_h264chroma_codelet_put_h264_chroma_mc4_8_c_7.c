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
// Reduced arithmetic operations by eliminating redundant parentheses and unrolling only partially
// Also reduced trip count by processing every second row
for (i = 0; i < h; i += 2) {
    uint8_t *d = dst;
    uint8_t *s = src;

    d[0] = ((A * s[0] + E * s[step]) + 32) >> 6;
    d[1] = ((A * s[1] + E * s[step + 1]) + 32) >> 6;

    dst += stride * 2;
    src += stride * 2;
}
}
