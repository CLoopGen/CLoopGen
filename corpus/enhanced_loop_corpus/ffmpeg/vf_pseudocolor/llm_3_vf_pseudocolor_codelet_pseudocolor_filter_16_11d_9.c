#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern  uint16_t *_usr_index;
extern  uint16_t *src;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided Memory Access with Indirect Indexing via Lookup Table
    // Use strided access pattern on the output and indirect write via precomputed indices
    // Also unroll by 2 to increase ILP and change access order to column-major for stress testing memory system

    uint16_t *src_base = src;
    uint16_t *dst_base = dst;
    ptrdiff_t sstep = slinesize / sizeof(uint16_t);
    ptrdiff_t dstep = dlinesize / sizeof(uint16_t);
    ptrdiff_t istep = ilinesize / sizeof(uint16_t);

    // Precompute vertical strides for index array
    int *row_map = (int*)alloca(height * sizeof(int));
    for (int i = 0; i < height; i++) {
        row_map[i] = (i >> 1) * istep;
    }

    // Transpose-like access: iterate over columns first, then rows (column-major)
    for (int x = 0; x < width; x++) {
        int ix = x >> 1;
        for (int y = 0; y < height; y++) {
            int mapped_row = row_map[y];
            int index_val = index[mapped_row + ix];
            float v = lut[index_val];

            uint16_t result = (v >= 0 && v <= max) ? (uint16_t)v : src_base[y * sstep + x];
            dst_base[y * dstep + x] = result;
        }
    }
}
