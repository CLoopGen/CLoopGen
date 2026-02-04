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
    // Use indirect indexing via array of offsets to simulate irregular access
    // Assume small fixed offset pattern for realism and safety
    static const int32_t offsets[] = {0, 4, 8, 12};
    const int num_offsets = 4;

    for (loop_cnt = (height >> 1); loop_cnt--;) {
        int i;
        // Strided but unrolled with indirect offset access
        for (i = 0; i < num_offsets; ++i) {
            int32_t idx_src = (offsets[i] + (src - &src[0])) % 64; // Simulate cache-line variation
            int32_t idx_dst = (offsets[i] + (dst - &dst[0])) % 64;
            dst[idx_dst] = src[idx_src];
        }

        // Progress primary pointers by double stride as in original
        src += (src_stride << 1);
        dst += (dst_stride << 1);
    }
}
