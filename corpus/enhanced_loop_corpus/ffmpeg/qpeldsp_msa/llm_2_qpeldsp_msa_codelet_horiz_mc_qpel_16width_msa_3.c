#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of striding by src_stride per row, process 4 consecutive rows as a block with unit stride
    uint8_t *s = src;
    uint8_t *d = dst;
    for (loop_count = (height >> 2); loop_count--;) {
        for (int i = 0; i < 4; ++i) {
            // Process each of the 4 rows consecutively in memory
            for (int j = 0; j < src_stride; ++j) {
                d[j] = s[j]; // Simulate simple copy with unit stride
            }
            s += src_stride;
            d += dst_stride;
        }
    }
}
