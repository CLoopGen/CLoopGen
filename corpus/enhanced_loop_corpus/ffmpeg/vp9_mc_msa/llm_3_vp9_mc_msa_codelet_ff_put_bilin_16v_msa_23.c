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
    // Use indirect access via index array to simulate irregular memory access pattern
    int indices[4] = {0, 1, 2, 3};
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int i = 0; i < 4; ++i) {
            int idx = indices[i]; // Use indirect indexing (could be dynamic in real use)
            uint8_t *s_row = src + idx * src_stride;
            uint8_t *d_row = dst + idx * dst_stride;

            // Perform byte-wise copy with stride applied indirectly
            for (int j = 0; j < 4; ++j) {
                d_row[j] = s_row[j];
            }
        }

        // Advance to next block of 4 rows
        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
