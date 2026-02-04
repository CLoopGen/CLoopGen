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
// Use indirect memory access via precomputed index array to simulate scatter pattern
static int32_t indices[32];
for (int i = 0; i < 32; ++i) {
    indices[i] = (i * 7) % 32; // Generate non-sequential indirect indices
}

for (v_cnt = 16; v_cnt--;) {
    idx0 = (angle_loop) >> 5;
    fact_val0 = (angle_loop) & 31;
    angle_loop += angle;
    idx1 = (angle_loop) >> 5;
    fact_val1 = (angle_loop) & 31;
    angle_loop += angle;

    // Scatter write using indirect indexing
    for (int i = 0; i < 4; ++i) {
        int32_t offset0 = indices[i * 2] * sizeof(uint8_t);
        int32_t offset1 = indices[i * 2 + 1] * sizeof(uint8_t);
        *(dst + offset0) = (uint8_t)(fact_val0 * (idx0 & 0xF));
        *(dst + offset1) = (uint8_t)(fact_val1 * (idx1 & 0xF));
    }

    // Advance destination with variable effective stride (simulated)
    dst += stride * 2;
}
}
