#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_local = src;
    int16_t *dst_local = dst;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Introduce local variables to break direct dependencies
        uint8_t val0 = src_local[0];
        uint8_t val1 = src_local[src_stride];
        uint8_t val2 = src_local[1];
        uint8_t val3 = src_local[src_stride + 1];

        // Create artificial RAW dependency chain
        int16_t accum = 0;
        accum += val0; accum *= 2;
        accum += val1; accum *= 2;
        accum += val2; accum *= 2;
        accum += val3;

        dst_local[0] = accum;
        dst_local[dst_stride] = accum >> 1;

        // Update pointers with stride
        src_local += (2 * src_stride);
        dst_local += (2 * dst_stride);
    }
    // Write back to global pointers if needed (assuming side effects matter)
    src = src_local;
    dst = dst_local;
}
