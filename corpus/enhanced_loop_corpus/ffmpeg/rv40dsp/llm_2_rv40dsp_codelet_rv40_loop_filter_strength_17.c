#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int step;
extern ptrdiff_t stride;
extern int sum_p1p0;
extern int sum_q1q0;
extern uint8_t *ptr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled with offset adjustments)
    sum_p1p0 = 0;
    sum_q1q0 = 0;
    uint8_t *p0 = src - 2 * step;
    uint8_t *q0 = src;
    for (i = 0; i < 4; i++) {
        sum_p1p0 += p0[0] - p0[step];
        sum_q1q0 += q0[step] - q0[0];
        p0 += stride;
        q0 += stride;
    }
}
