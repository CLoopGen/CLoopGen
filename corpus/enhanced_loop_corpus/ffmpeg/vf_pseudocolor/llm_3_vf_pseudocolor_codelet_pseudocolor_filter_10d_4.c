#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided Memory Access with Transposed Layout Simulation
    // Instead of row-major, simulate access in strided column-major fashion
    // This changes the memory access pattern to favor vertical traversal (strided over rows)
    // We iterate by columns first, then rows, to create stride-based access on all arrays.

    for (x = 0; x < width; x++) {
        uint8_t *idx_col = index + (x >> 1);
        uint8_t *src_col = src + x;
        uint8_t *dst_col = dst + x;

        for (y = 0; y < height; y++) {
            int v = lut[*idx_col];
            if (v >= 0 && v <= max) {
                *dst_col = v;
            } else {
                *dst_col = *src_col;
            }

            // Move down one row (strided access)
            idx_col += ilinesize;
            src_col += slinesize;
            dst_col += dlinesize;
        }
    }
}
