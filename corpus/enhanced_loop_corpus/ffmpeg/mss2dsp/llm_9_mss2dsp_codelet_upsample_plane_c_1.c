#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern uint8_t *src1;
extern uint8_t *src2;
extern uint8_t *dst1;
extern uint8_t *dst2;
extern uint8_t a;
extern uint8_t b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (w - 1) >> 1; i >= 0; i -= 2) {
    uint8_t a1 = src1[i],     b1 = src2[i];
    uint8_t a2 = src1[i-1],   b2 = src2[i-1];
    dst1[i]   = (5 * a1 + 2 * b1 + 3) >> 3;
    dst2[i]   = (2 * a1 + 5 * b1 + 3) >> 3;
    dst1[i-1] = (5 * a2 + 2 * b2 + 3) >> 3;
    dst2[i-1] = (2 * a2 + 5 * b2 + 3) >> 3;
}
}
