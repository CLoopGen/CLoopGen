#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *srow;
    uint8_t *drow;
    uint32_t acc[4] = {0};

    srow = src;
    drow = dst;

    acc[0] = srow[0] + srow[1];
    acc[1] = srow[src_stride] + srow[src_stride + 1];
    acc[2] = srow[2*src_stride] + srow[2*src_stride + 1];
    acc[3] = srow[3*src_stride] + srow[3*src_stride + 1];

    drow[0] = (uint8_t)(acc[0] & 0xFF);
    drow[dst_stride] = (uint8_t)((acc[0] + acc[1]) & 0xFF);
    drow[2*dst_stride] = (uint8_t)((acc[1] + acc[2]) & 0xFF);
    drow[3*dst_stride] = (uint8_t)((acc[2] + acc[3]) & 0xFF);

    acc[0] += drow[0];
    acc[1] += drow[dst_stride];
    acc[2] += drow[2*dst_stride];
    acc[3] += drow[3*dst_stride];

    drow[1] = (uint8_t)(acc[0] & 0xFF);
    drow[dst_stride + 1] = (uint8_t)(acc[1] & 0xFF);
    drow[2*dst_stride + 1] = (uint8_t)(acc[2] & 0xFF);
    drow[3*dst_stride + 1] = (uint8_t)(acc[3] & 0xFF);

    srow += 2;
    drow += 2;

    for (int i = 0; i < 4; ++i) {
        uint32_t val = *(uint32_t*)(srow + i * src_stride);
        *(uint32_t*)(drow + i * dst_stride) = val ^ 0xAAAAAAAA;
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
