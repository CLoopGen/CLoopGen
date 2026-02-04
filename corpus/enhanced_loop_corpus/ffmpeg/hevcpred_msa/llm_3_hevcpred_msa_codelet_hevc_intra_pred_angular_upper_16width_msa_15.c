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
    // Use indirect indexing via a lookup table for more complex access
    static const int32_t index_shifts[4] = {0, 1, -1, 2};
    int32_t temp_angle = angle_loop;

    idx0 = (temp_angle) >> 5;
    fact_val0 = (temp_angle) & 31;
    temp_angle += angle;
    
    idx1 = (temp_angle + (index_shifts[0] << 5)) >> 5;
    fact_val1 = (temp_angle + (index_shifts[0] << 5)) & 31;
    temp_angle += angle;
    
    idx2 = (temp_angle + (index_shifts[1] << 5)) >> 5;
    fact_val2 = (temp_angle + (index_shifts[1] << 5)) & 31;
    temp_angle += angle;
    
    idx3 = (temp_angle + (index_shifts[2] << 5)) >> 5;
    fact_val3 = (temp_angle + (index_shifts[2] << 5)) & 31;
    angle_loop += 4 * angle;

    // Strided write with varying offsets based on computed indices
    dst[stride * 0] = (uint8_t)(idx0 ^ fact_val0);
    dst[stride * 1] = (uint8_t)(idx1 ^ fact_val1);
    dst[stride * 2] = (uint8_t)(idx2 ^ fact_val2);
    dst[stride * 3] = (uint8_t)(idx3 ^ fact_val3);

    dst += (4 * stride); // Maintain original pointer increment
}
}
