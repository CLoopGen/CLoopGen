#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change to indirect access using an index array for non-sequential row access
int indices[4] = {0, 2, 1, 3}; // Example of reordered access pattern

for (cnt = (height >> 2); cnt--;) {
    for (int i = 0; i < 4; ++i) {
        int idx = indices[i];
        uint8_t *s_row = src + (idx * src_stride);
        uint8_t *d_row = dst + (idx * dst_stride);

        // Simulate processing each indirectly addressed row
        for (int j = 0; j < 16; ++j) {
            d_row[j] = s_row[j] ^ 0xFF; // Example transform: bitwise NOT
        }
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
