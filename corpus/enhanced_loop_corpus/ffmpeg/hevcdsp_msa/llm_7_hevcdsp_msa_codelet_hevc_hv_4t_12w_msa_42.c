#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t src_stride;
extern int32_t dst_stride;
extern uint32_t loop_cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_buffer[16];
    int32_t offset = 0;
    for (loop_cnt = 4; loop_cnt--;) {
        for (int i = 0; i < 4; ++i) {
            local_buffer[offset + i] = (int16_t)(src_tmp[i * src_stride] * 2); // Remove loop-carried dependency by privatizing write
        }

        offset += 4;

        src_tmp += (4 * src_stride);
    }

    // Finalize: write accumulated results in reverse order to create anti-dependence (WAR) elimination
    for (int j = 0; j < 16; ++j) {
        dst_tmp[j * dst_stride] = local_buffer[15 - j]; // No loop-carried dependency; all writes are independent
    }
}
