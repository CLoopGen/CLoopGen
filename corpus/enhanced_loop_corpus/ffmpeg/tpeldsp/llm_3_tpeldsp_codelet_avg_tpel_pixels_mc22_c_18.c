#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed indexing (accessing down columns first)
    // Simulates column-major traversal to change spatial locality and access pattern
    for (j = 0; j < width; j++) {
        for (i = 0; i < height; i++) {
            int idx = i * stride + j;  // Current pixel index in column j, row i
            int below_idx = idx + stride; // Pixel directly below
            int right_idx = idx + 1;     // Pixel to the right
            int diag_idx = below_idx + 1; // Diagonal pixel (below-right)

            // Ensure we don't go out of bounds on last row or last column
            if (i < height - 1 && j < width - 1) {
                dst[idx] = (dst[idx] + 
                    (((2 * src[idx] + 3 * src[right_idx] + 3 * src[below_idx] + 4 * src[diag_idx] + 6) * 2731) >> 15) + 1) >> 1;
            } else {
                // Fallback: use only available neighbors (edge handling)
                int coeff_sum = 2 * src[idx];
                if (j < width - 1) coeff_sum += 3 * src[right_idx];
                if (i < height - 1) coeff_sum += 3 * src[below_idx];
                if (i < height - 1 && j < width - 1) coeff_sum += 4 * src[diag_idx];
                dst[idx] = (dst[idx] + (((coeff_sum + 6) * 2731) >> 15) + 1) >> 1;
            }
        }
    }
    // Adjust global src/dst pointers as in original (side effect preserved)
    src += height * stride;
    dst += height * stride;
}
