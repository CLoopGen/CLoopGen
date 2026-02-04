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
    // Variant 2: Strided memory access pattern with transposed write
    // Read source in vertical strided pattern (every src_stride byte), then write to destination in transposed layout
    uint8_t *s = src;
    uint8_t *d = dst;
    for (loop_count = (height >> 2); loop_count--;) {
        // Process 4 horizontal pixels across multiple rows — simulate vector-like vertical access
        for (int col = 0; col < src_stride; ++col) {
            d[col + 0 * dst_stride] = s[col + 0 * src_stride];
            d[col + 1 * dst_stride] = s[col + 1 * src_stride];
            d[col + 2 * dst_stride] = s[col + 2 * src_stride];
            d[col + 3 * dst_stride] = s[col + 3 * src_stride];
        }
        // Advance to next 4-row block
        s += 4 * src_stride;
        d += 4 * dst_stride;
    }
}
