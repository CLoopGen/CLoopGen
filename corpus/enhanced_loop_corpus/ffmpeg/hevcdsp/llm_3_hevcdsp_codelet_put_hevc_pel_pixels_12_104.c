#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element first, then the odd-offset elements
    int16_t *dst_base = dst;
    uint16_t *src_row = src;
    ptrdiff_t dst_stride = 64;
    int shift = 14 - 12;

    // Process even and odd indices in separate passes (strided access with stride 2)
    for (y = 0; y < height; y++) {
        uint16_t *src_ptr = src_row;
        int16_t *dst_ptr = dst_base;

        // First pass: even indices (0, 2, 4, ...)
        for (x = 0; x < width; x += 2) {
            dst_ptr[x] = (int16_t)(src_ptr[x] << shift);
        }

        // Second pass: odd indices (1, 3, 5, ...)
        for (x = 1; x < width; x += 2) {
            dst_ptr[x] = (int16_t)(src_ptr[x] << shift);
        }

        src_row += srcstride;
        dst_base += dst_stride;
    }
}
