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
    for (i = 0, ptr = src; i < 4; i++, ptr += stride) {
        sum_p1p0 += (i >= 2) ? (ptr[-2 * step] - ptr[-1 * step]) : 0;
        sum_q1q0 += (i < 2)  ? (ptr[1 * step] - ptr[0 * step]) : 0;
    }
}
