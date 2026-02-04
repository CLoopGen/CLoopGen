#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *src_step = src;
uint8_t *dst_step = dst;
int32_t local_height = height / 8;
for (cnt = 0; cnt < local_height; cnt++) {
    // Eliminate loop-carried dependency on src/dst by using indexed access
    for (int i = 0; i < 8; i++) {
        *(dst_step + i * dst_stride) = *(src_step + i * src_stride);
    }
    src_step += 8 * src_stride;
    dst_step += 8 * dst_stride;
}
// Final update to original pointers to preserve observable state
src = src_step;
dst = dst_step;
}
