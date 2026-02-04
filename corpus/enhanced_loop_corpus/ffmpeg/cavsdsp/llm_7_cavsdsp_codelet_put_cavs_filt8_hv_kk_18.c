#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Eliminate some RAW dependencies by reordering and precomputing values used multiple times
    const int tbase = tmp[0 * 8];
    const int tmp_offsets[] = {
        tmp[-2 * 8], tmp[-1 * 8], tbase, tmp[1 * 8], tmp[2 * 8],
        tmp[3 * 8], tmp[4 * 8], tmp[5 * 8], tmp[6 * 8], tmp[7 * 8], tmp[8 * 8], tmp[9 * 8], tmp[10 * 8]
    };

    // Precompute common subexpressions to reduce redundant loads and remove potential aliasing effects
    const int c0 = (-1 * tmp_offsets[1] + 5 * tmp_offsets[2] + 5 * tmp_offsets[3] - 1 * tmp_offsets[4]);
    const int c1 = (-1 * tmp_offsets[2] + 5 * tmp_offsets[3] + 5 * tmp_offsets[4] - 1 * tmp_offsets[5]);
    const int c2 = (-1 * tmp_offsets[3] + 5 * tmp_offsets[4] + 5 * tmp_offsets[5] - 1 * tmp_offsets[6]);
    const int c3 = (-1 * tmp_offsets[4] + 5 * tmp_offsets[5] + 5 * tmp_offsets[6] - 1 * tmp_offsets[7]);
    const int c4 = (-1 * tmp_offsets[5] + 5 * tmp_offsets[6] + 5 * tmp_offsets[7] - 1 * tmp_offsets[8]);
    const int c5 = (-1 * tmp_offsets[6] + 5 * tmp_offsets[7] + 5 * tmp_offsets[8] - 1 * tmp_offsets[9]);
    const int c6 = (-1 * tmp_offsets[7] + 5 * tmp_offsets[8] + 5 * tmp_offsets[9] - 1 * tmp_offsets[10]);
    const int c7 = (-1 * tmp_offsets[8] + 5 * tmp_offsets[9] + 5 * tmp_offsets[10]);

    // Store results directly using precomputed coefficients, removing repeated indexing
    dst[0 * dstStride] = cm[(c0 + 512) >> 10];
    dst[1 * dstStride] = cm[(c1 + 512) >> 10];
    dst[2 * dstStride] = cm[(c2 + 512) >> 10];
    dst[3 * dstStride] = cm[(c3 + 512) >> 10];
    dst[4 * dstStride] = cm[(c4 + 512) >> 10];
    dst[5 * dstStride] = cm[(c5 + 512) >> 10];
    dst[6 * dstStride] = cm[(c6 + 512) >> 10];
    dst[7 * dstStride] = cm[(c7 + 512) >> 10];

    dst++;
    tmp++;
}
}
