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
    // Variant 2: Strided memory access - transposed traversal (column-major order)
    // Instead of row-by-row, we process column-by-column to change cache access pattern.
    // This alters spatial locality and may affect performance depending on cache size.
    for (j = 0; j < width; j++) {
        for (i = 0; i < height; i++) {
            int idx = i * stride + j;  // Current pixel index in source
            int src_idx_next_row = idx + stride;
            // Access current and neighboring pixels using strided offsets
            dst[idx] = ((4 * src[idx] + 
                         3 * ((j + 1 < width) ? src[idx + 1] : src[idx]) + 
                         3 * ((i + 1 < height) ? src[src_idx_next_row] : src[idx]) + 
                         2 * ((i + 1 < height && j + 1 < width) ? src[src_idx_next_row + 1] : src[idx]) + 6) * 2731) >> 15;
        }
    }
    // Adjust global pointers as in original (simulate side effect)
    src += height * stride;
    dst += height * stride;
}
