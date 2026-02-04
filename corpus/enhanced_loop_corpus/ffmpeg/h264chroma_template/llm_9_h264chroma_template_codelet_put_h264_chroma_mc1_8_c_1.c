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
    int val1 = A * src[0];
    int val2 = E * src[step + 0];
    int val3 = val1 + val2 + 16;
    int val4 = (val3 + (val3 >> 4)) >> 5; // Approximate scaling with more operations
    dst[0] = val4 & 0xFF;
    dst += stride;
    src += stride;
}
}
