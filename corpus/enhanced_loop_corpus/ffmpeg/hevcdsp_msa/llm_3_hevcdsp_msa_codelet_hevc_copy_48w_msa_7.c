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
    // Variant 2: Strided access pattern - traverse columns instead of rows
    // Assume we are processing a fixed width (e.g., 4 elements per row) but stepping through vertically
    const int width = 4;

    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int col = 0; col < width; ++col) {
            // Access every fourth element in a column-wise fashion across multiple rows
            int32_t offset0 = col;
            int32_t offset1 = col + src_stride;
            int32_t offset2 = col + 2 * src_stride;
            int32_t offset3 = col + 3 * src_stride;

            // Gather data from strided locations in src
            uint8_t val0 = src[offset0];
            uint8_t val1 = src[offset1];
            uint8_t val2 = src[offset2];
            uint8_t val3 = src[offset3];

            // Scatter results into dst using same strided pattern
            dst[col] = (int16_t)(val0 + val1);
            dst[col + dst_stride] = (int16_t)(val2 + val3);
            dst[col + 2 * dst_stride] = (int16_t)(val0 + val2);
            dst[col + 3 * dst_stride] = (int16_t)(val1 + val3);
        }

        // Move base pointers forward by 4 rows
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
