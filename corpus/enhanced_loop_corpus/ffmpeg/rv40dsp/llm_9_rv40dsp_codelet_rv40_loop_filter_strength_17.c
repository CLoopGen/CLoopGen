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
for (i = 0, ptr = src; i < 2; i++, ptr += 2 * stride) {
    int temp_p = ptr[-2 * step] - ptr[-1 * step];
    int temp_q = ptr[1 * step] - ptr[0 * step];
    sum_p1p0 += temp_p;
    sum_q1q0 += temp_q;
    sum_p1p0 += ptr[stride - 2 * step] - ptr[stride - 1 * step];
    sum_q1q0 += ptr[stride + 1 * step] - ptr[stride + 0 * step];
}
}
