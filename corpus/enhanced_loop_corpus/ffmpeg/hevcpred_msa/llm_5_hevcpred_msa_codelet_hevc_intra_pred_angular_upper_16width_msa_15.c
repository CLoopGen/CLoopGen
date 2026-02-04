#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern int32_t v_cnt;
extern int32_t idx0;
extern int32_t fact_val0;
extern int32_t idx1;
extern int32_t fact_val1;
extern int32_t idx2;
extern int32_t fact_val2;
extern int32_t idx3;
extern int32_t fact_val3;
extern int32_t angle;
extern int32_t angle_loop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (v_cnt = 4; v_cnt--;) {
    idx0 = (angle_loop) >> 5;
    fact_val0 = (angle_loop) & 31;
    angle_loop += angle;

    if (idx0 % 2 == 0) {
        idx1 = (angle_loop) >> 5;
        fact_val1 = (angle_loop) & 31;
        angle_loop += angle;
    } else {
        idx1 = 0;
        fact_val1 = 0;
        angle_loop += angle; // Still consume angle step
    }

    idx2 = (angle_loop) >> 5;
    fact_val2 = (angle_loop) & 31;
    angle_loop += angle;

    if (idx2 % 2 == 1) {
        idx3 = (angle_loop) >> 5;
        fact_val3 = (angle_loop) & 31;
        angle_loop += angle;
    } else {
        idx3 = idx2;
        fact_val3 = 0;
        // Still advance angle
        angle_loop += angle;
    }

    {
        dst += stride;
    }
    {
        dst += stride;
    }
    {
        dst += stride;
    }
    {
        dst += stride;
    }

    dst += (4 * stride);
}
}
