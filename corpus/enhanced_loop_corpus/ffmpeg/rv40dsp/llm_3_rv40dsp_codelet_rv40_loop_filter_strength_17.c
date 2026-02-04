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
    // Variant 2: Strided Access with Fixed Index Scaling (explicit stride multiplication)
    sum_p1p0 = 0;
    sum_q1q0 = 0;
    ptrdiff_t idx;
    for (i = 0; i < 4; i++) {
        idx = i * stride / sizeof(uint8_t); // Normalize to byte index
        sum_p1p0 += src[idx - 2 * step] - src[idx - 1 * step];
        sum_q1q0 += src[idx + 1 * step] - src[idx + 0 * step];
    }
}
