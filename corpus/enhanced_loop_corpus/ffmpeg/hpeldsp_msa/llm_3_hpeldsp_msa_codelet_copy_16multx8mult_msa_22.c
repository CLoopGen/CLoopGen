#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        // Interleaved vertical access with strided pattern: process two rows at a time with stride jumps
        for (int i = 0; i < 8; i += 2) {
            int src_offset1 = i * src_stride;
            int src_offset2 = (i + 1) * src_stride;
            int dst_offset1 = i * dst_stride;
            int dst_offset2 = (i + 1) * dst_stride;

            // Consecutive horizontal write from strided reads
            for (int j = 0; j < 8; ++j) {
                dst_tmp[dst_offset1 + j] = src_tmp[src_offset1 + j];
                dst_tmp[dst_offset2 + j] = src_tmp[src_offset2 + j];
            }
        }

        // Update block pointers by 8 rows
        src_tmp += (8 * src_stride);
        dst_tmp += (8 * dst_stride);
    }
    // Move source and destination horizontally by 16 bytes (SIMD-like width step)
    src += 16;
    dst += 16;
}
}
