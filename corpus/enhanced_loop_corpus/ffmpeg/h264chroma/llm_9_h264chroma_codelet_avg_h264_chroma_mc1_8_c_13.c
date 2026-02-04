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
    int sum = val1 + val2 + 32;
    int shifted = sum >> 6;
    int avg = (dst[0] + shifted + 1) >> 1;
    dst[0] = avg;
    dst += stride;
    src += stride;
}
}
