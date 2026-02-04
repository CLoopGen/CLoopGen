#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width >> 4; cnt--;) {
        src_tmp = src;
        dst_tmp = dst;
        
        // Unroll the inner loop with consecutive memory access for better spatial locality
        for (loop_cnt = (height >> 2); loop_cnt--;) {
            // Process 4 rows at a time with direct, consecutive accesses
            dst_tmp[0 * dst_stride] = src_tmp[0 * src_stride];
            dst_tmp[1 * dst_stride] = src_tmp[1 * src_stride];
            dst_tmp[2 * dst_stride] = src_tmp[2 * src_stride];
            dst_tmp[3 * dst_stride] = src_tmp[3 * src_stride];

            // Advance source and destination pointers by 4 rows
            src_tmp += (4 * src_stride);
            dst_tmp += (4 * dst_stride);
        }
        src += 16;
        dst += 16;
    }
}
