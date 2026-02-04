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
    int temp_p1p0 = 0;
    int temp_q1q0 = 0;
    uint8_t *local_ptr = src;
    for (i = 0; i < 4; i++, local_ptr += stride) {
        temp_p1p0 += local_ptr[-2 * step] - local_ptr[-1 * step];
        temp_q1q0 += local_ptr[1 * step] - local_ptr[0 * step];
    }
    sum_p1p0 += temp_p1p0;
    sum_q1q0 += temp_q1q0;
}
