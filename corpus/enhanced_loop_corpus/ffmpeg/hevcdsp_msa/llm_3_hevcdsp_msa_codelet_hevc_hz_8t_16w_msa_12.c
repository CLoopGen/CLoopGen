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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        int32_t offset;
        // Use strided memory access with increasing offsets in strides of 4
        for (offset = 0; offset < dst_stride && offset < src_stride; offset += 4) {
            if ((offset + 3) < 256) {  // Prevent out-of-bounds on src
                dst[offset]           = (int16_t)src[offset];
                dst[dst_stride + offset] = (int16_t)src[src_stride + offset];
            }
        }

        // Update base pointers using stride
        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
