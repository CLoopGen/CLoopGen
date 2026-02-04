#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int step;
extern ptrdiff_t stride;
extern int sum_p1p2;
extern int sum_q1q2;
extern uint8_t *ptr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, ptr = src; i < 4; i++, ptr += stride) {
        if (i % 2 == 0) {
            sum_p1p2 += ptr[-2 * step] - ptr[-3 * step];
        } else {
            sum_q1q2 += ptr[1 * step] - ptr[2 * step];
        }
    }
}
