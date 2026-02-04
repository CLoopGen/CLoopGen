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
    idx1 = (angle_loop) >> 5;
    fact_val1 = (angle_loop) & 31;
    angle_loop += angle;
    idx2 = (angle_loop) >> 5;
    fact_val2 = (angle_loop) & 31;
    angle_loop += angle;
    idx3 = (angle_loop) >> 5;
    fact_val3 = (angle_loop) & 31;
    angle_loop += angle;

    if (fact_val0 < 16) {
        dst += stride;
    }
    if (fact_val1 < 16) {
        dst += stride;
    }
    if (fact_val2 < 16) {
        dst += stride;
    }
    if (fact_val3 < 16) {
        dst += stride;
    }

    dst += (4 * stride);
}
}
