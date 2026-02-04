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
    uint8_t prev_a = 0, prev_b = 0;
    int offset = (w - 1) >> 1;
    for (i = offset; i >= 0; i--) {
        a = src1[i] + prev_a; // Introduce loop-carried dependency (WAW/RAR via `a`)
        b = src2[i] + prev_b; // Introduce loop-carried dependency (WAW/RAR via `b`)
        dst1[i] = (3 * a + b + 2) >> 2;
        dst2[i] = (a + 3 * b + 2) >> 2;
        prev_a = a; // Carry value to next iteration
        prev_b = b;
    }
}
