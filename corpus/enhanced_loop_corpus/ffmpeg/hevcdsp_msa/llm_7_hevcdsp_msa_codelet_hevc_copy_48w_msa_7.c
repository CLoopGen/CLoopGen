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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t temp[4];
    temp[0] = src[0];
    temp[1] = src[src_stride];
    temp[2] = src[2*src_stride];
    temp[3] = src[3*src_stride];

    int32_t sum = temp[0] + temp[1] + temp[2] + temp[3];

    dst[0] = (int16_t)sum;
    dst[dst_stride] = (int16_t)(sum >> 1);
    dst[2*dst_stride] = (int16_t)(sum >> 2);
    dst[3*dst_stride] = (int16_t)(sum >> 3);

    sum += dst[0]; // Introduce WAW and RAW dependency across iterations

    src += 4 * src_stride;
    dst += 4 * dst_stride;

    // Add artificial dependency: current iteration depends on prior `sum`
    // This creates a loop-carried dependency, reducing parallelism
}
}
