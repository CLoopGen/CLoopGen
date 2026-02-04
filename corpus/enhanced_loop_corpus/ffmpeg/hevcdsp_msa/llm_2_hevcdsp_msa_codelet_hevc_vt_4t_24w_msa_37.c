#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Variant 1: Consecutive memory access with local accumulation
        int32_t row_offset;
        
        // Process 4 rows, accessing src and dst in a blocked, consecutive pattern
        for (int i = 0; i < 4; i++) {
            row_offset = i * src_stride;
            int16_t *d = dst + i * (dst_stride >> 1);
            const uint8_t *s = src + row_offset;

            // Simulate meaningful access: convert 8 pixels per row
            for (int j = 0; j < 8; j++) {
                d[j] = (int16_t)s[j];
            }
        }

        // Advance pointers by 4 rows
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
