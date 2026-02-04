#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix1;
extern uint8_t *pix2;
extern ptrdiff_t line_size;
extern int w;
extern int h;
extern int i;
extern int j;
extern int tmp[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed indexing
    // Instead of row-major access, simulate a column-major-like pattern in tmp
    // We still process pixels row by row, but store into tmp using a transposed index
    // This creates a strided access pattern in tmp: writing to (j*height + i) locations
    // Assumes w <= 32 and h <= 32 for safety within tmp bounds (as implied by original 32*i+j)
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j += 4) {
            // Transpose storage: each column of output becomes a contiguous block
            tmp[32 * j + i + 0] = (pix1[j + 0] - pix2[j + 0]) << 4;
            if (j + 1 < w) tmp[32 * (j + 1) + i] = (pix1[j + 1] - pix2[j + 1]) << 4;
            if (j + 2 < w) tmp[32 * (j + 2) + i] = (pix1[j + 2] - pix2[j + 2]) << 4;
            if (j + 3 < w) tmp[32 * (j + 3) + i] = (pix1[j + 3] - pix2[j + 3]) << 4;
        }
        pix1 += line_size;
        pix2 += line_size;
    }
}
