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

    // Introduce artificial data dependencies: chain computations using previous values
    // Create WAW and RAW dependencies by reusing and updating shared variables
    int temp0 = idx0 + fact_val0;
    int temp1 = idx1 + fact_val1 + temp0;  // RAW on temp0
    int temp2 = idx2 + fact_val2 + temp1;  // RAW on temp1
    int temp3 = idx3 + fact_val3 + temp2;  // RAW on temp2

    // Loop-carried dependency: accumulate across iterations via static storage
    static int32_t accumulator = 0;
    accumulator += temp0 + temp1 + temp2 + temp3;
    dst[0] = (uint8_t)(accumulator & 0xFF);
    dst[stride] = (uint8_t)((accumulator >> 8) & 0xFF);

    dst += (4 * stride);
}
}
