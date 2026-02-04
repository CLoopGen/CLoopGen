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
        // Variant 2: Strided and interleaved access pattern
        // Access every other row with increasing stride offset to simulate non-unit stride

        // Interleaved pointer updates with strided indexing
        for (int i = 0; i < 4; i++) {
            // Use varying offsets with dynamic stride scaling
            int32_t idx_src = (i & 1) ? 3 * src_stride : 1 * src_stride;
            int32_t idx_dst = (i + 1) * (dst_stride);

            // Simulate data transfer with bounds-aware access
            for (int j = 0; j < 4; j++) {
                int src_pos = ((i + j) % 2) ? idx_src + j : idx_src - j;
                if (src_pos >= 0) {
                    ((int16_t*)dst)[idx_dst/sizeof(int16_t) + j] = (int16_t)(src[src_pos]);
                }
            }
        }

        // Update base pointers using larger jumps to maintain alignment with loop logic
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
