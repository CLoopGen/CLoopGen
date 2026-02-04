#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *src_local = src;
uint8_t *dst_local = dst;
ptrdiff_t local_stride = dst_stride;

for (loop_cnt = (height >> 2); loop_cnt--;) {
    dst_local[0] = src_local[0];
    dst_local[local_stride] = src_local[src_stride];
    dst_local[2 * local_stride] = src_local[2 * src_stride];
    dst_local[3 * local_stride] = src_local[3 * src_stride];

    ((uint32_t*)dst_local)[0] ^= ((uint32_t*)dst_local)[0]; // Introduce WAW dependency: write after write to same location
    ((uint32_t*)dst_local)[0] = 0; // Overwrite to create artificial dependence

    src_local += (4 * src_stride);
    dst_local += (4 * dst_stride);
}

dst = dst_local;
}
