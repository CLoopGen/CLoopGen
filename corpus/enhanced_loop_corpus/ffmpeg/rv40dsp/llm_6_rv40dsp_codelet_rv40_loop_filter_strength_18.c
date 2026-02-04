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
    int temp_sum_p1p2 = 0;
    int temp_sum_q1q2 = 0;
    uint8_t *temp_ptr = src;
    for (i = 0; i < 4; i++) {
        temp_sum_p1p2 += temp_ptr[-2 * step] - temp_ptr[-3 * step];
        temp_sum_q1q2 += temp_ptr[step] - temp_ptr[2 * step];
        temp_ptr += stride;
    }
    sum_p1p2 += temp_sum_p1p2;
    sum_q1q2 += temp_sum_q1q2;
}
