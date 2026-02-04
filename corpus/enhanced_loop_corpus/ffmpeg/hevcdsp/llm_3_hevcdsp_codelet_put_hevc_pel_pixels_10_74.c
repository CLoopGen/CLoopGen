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
    // Variant 2: Strided memory access — process every 2nd element in forward and backward pass
    int16_t *dst_ptr = dst;
    uint16_t *src_row = src;
    for (y = 0; y < height; y++) {
        uint16_t *src_ptr = src_row;

        // Forward pass: even indices
        for (x = 0; x < width; x += 2) {
            dst_ptr[x] = src_ptr[x] << (14 - 10);
        }

        // Backward pass: odd indices
        for (x = (width % 2 == 0) ? width - 1 : width - 2; x > 0; x -= 2) {
            dst_ptr[x] = src_ptr[x] << (14 - 10);
        }

        src_row += srcstride;
        dst_ptr += 64;
    }
}
