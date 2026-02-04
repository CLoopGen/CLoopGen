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
    sum_p1p2 = 0;
    sum_q1q2 = 0;
    uint8_t *local_ptr = src;
    int prev_val = local_ptr[-3 * step];
    int current_val;
    for (i = 0; i < 4; i++, local_ptr += stride) {
        current_val = local_ptr[-2 * step];
        sum_p1p2 += current_val - prev_val;
        prev_val = local_ptr[-2 * step];
        sum_q1q2 += local_ptr[step] - local_ptr[2 * step];
    }
}
