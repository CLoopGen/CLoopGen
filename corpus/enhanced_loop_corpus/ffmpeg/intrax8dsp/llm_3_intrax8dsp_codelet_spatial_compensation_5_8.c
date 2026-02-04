#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed offsets
    ptrdiff_t offset_base_src1 = (8) + 9;          // Base for negative case
    ptrdiff_t offset_base_src2 = (8 + 8 + 1);      // Base for non-negative case
    for (y = 0; y < 8; y++) {
        const int y_shift = (y + 1) >> 1;
        uint8_t *dst_ptr = dst;
        for (x = 0; x < 8; x++) {
            if (2 * x - y < 0) {
                dst_ptr[x] = *(src + offset_base_src1 + 2 * x - y);
            } else {
                dst_ptr[x] = *(src + offset_base_src2 + x - y_shift);
            }
        }
        dst += stride;
    }
}
