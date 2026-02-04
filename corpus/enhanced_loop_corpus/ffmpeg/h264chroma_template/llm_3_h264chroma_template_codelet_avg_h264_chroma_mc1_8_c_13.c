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
    ptrdiff_t read_idx = i * stride;
    ptrdiff_t write_idx = i * stride;
    uint8_t temp1 = src[read_idx];
    uint8_t temp2 = src[read_idx + step];
    dst[write_idx] = (((dst[write_idx]) + ((((A * temp1 + E * temp2)) + 32) >> 6) + 1) >> 1);
}
}
