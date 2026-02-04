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
    for (i = 0; i < 4; i++) {
        ptr = src + i * stride;
        sum_p1p0 += ptr[-2 * step] - ptr[-1 * step];
        sum_q1q0 += ptr[1 * step] - ptr[0 * step];
    }
}
