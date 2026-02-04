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
extern int32_t angle;
extern int32_t angle_loop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (v_cnt = 16; v_cnt--;) {
    idx0 = (angle_loop) >> 5;
    fact_val0 = (angle_loop) & 31;
    angle_loop += angle;
    idx1 = (angle_loop) >> 5;
    fact_val1 = (angle_loop) & 31;
    angle_loop += angle;

    // Unroll the memory access with consecutive writes to simulate burst-like behavior
    // Assume dst is aligned and we're writing 8 pairs of values with fixed stride steps
    for (int i = 0; i < 2; ++i) {
        dst[i * stride] = (uint8_t)(idx0 + fact_val0);
        dst[i * stride + 1] = (uint8_t)(idx1 + fact_val1);
    }
    dst += 2 * stride;

    for (int i = 0; i < 2; ++i) {
        dst[i * stride] = (uint8_t)(idx0 ^ fact_val1);
        dst[i * stride + 1] = (uint8_t)(idx1 ^ fact_val0);
    }
    dst += 2 * stride;
}
}
