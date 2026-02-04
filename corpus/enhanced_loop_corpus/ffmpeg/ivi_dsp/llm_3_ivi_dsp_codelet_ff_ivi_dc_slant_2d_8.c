#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive linear access using flattened index (coalesced store pattern)
    int16_t *base = out;
    int total_elements = blk_size * blk_size;
    ptrdiff_t stride = pitch / sizeof(int16_t); // Convert byte pitch to element count
    for (int i = 0; i < total_elements; i++) {
        int row = i / blk_size;
        int col = i % blk_size;
        base[row * stride + col] = dc_coeff;
    }
}
