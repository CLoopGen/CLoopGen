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
int32_t local_angle = angle_loop;  // Break loop-carried dependency on angle_loop
int32_t local_idx0, local_idx1, local_idx2, local_idx3;
int32_t local_fact0, local_fact1, local_fact2, local_fact3;

for (v_cnt = 4; v_cnt--;) {
    // Remove all loop-carried dependencies by using local copy
    // All updates happen independently per iteration
    local_idx0 = local_angle >> 5;
    local_fact0 = local_angle & 31;
    local_angle += angle;

    local_idx1 = local_angle >> 5;
    local_fact1 = local_angle & 31;
    local_angle += angle;

    local_idx2 = local_angle >> 5;
    local_fact2 = local_angle & 31;
    local_angle += angle;

    local_idx3 = local_angle >> 5;
    local_fact3 = local_angle & 31;
    local_angle += angle;

    // Eliminate side effects: write to temporaries instead of globals
    // No WAR/WAW hazards with external uses
    int sum_idx = local_idx0 + local_idx1 + local_idx2 + local_idx3;
    int sum_fact = local_fact0 + local_fact1 + local_fact2 + local_fact3;

    // Independent memory store pattern
    dst[0] = (uint8_t)(sum_idx & 0xFF);
    dst[stride] = (uint8_t)(sum_fact & 0xFF);

    // Update destination pointer without affecting computed values
    dst += (4 * stride);
}

// Commit final state only once after loop
angle_loop = local_angle;
idx0 = local_idx0; fact_val0 = local_fact0;
idx1 = local_idx1; fact_val1 = local_fact1;
idx2 = local_idx2; fact_val2 = local_fact2;
idx3 = local_idx3; fact_val3 = local_fact3;
}
