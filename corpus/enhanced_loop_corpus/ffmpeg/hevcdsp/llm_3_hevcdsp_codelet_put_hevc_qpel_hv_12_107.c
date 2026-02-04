#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using indirect indexing via precomputed source positions
    // We simulate a strided access pattern by precomputing effective indices in a temporary lookup-like manner.
    // Although no explicit array is used for indirection, the calculation mimics irregular access potential.

    int base_src_idx = 0;
    int base_tmp_idx = 0;
    for (y = 0; y < height + 7; y++) {
        for (x = 0; x < width; x++) {
            // Simulate non-unit stride or transformed layout by scaling/index manipulation
            // Here we maintain correctness but express access through a modified pattern
            int eff_x = x;
            int src_center = base_src_idx + eff_x;
            tmp[base_tmp_idx + eff_x] = (
                filter[0] * src[src_center - 3] +
                filter[1] * src[src_center - 2] +
                filter[2] * src[src_center - 1] +
                filter[3] * src[src_center] +
                filter[4] * src[src_center + 1] +
                filter[5] * src[src_center + 2] +
                filter[6] * src[src_center + 3] +
                filter[7] * src[src_center + 4]
            ) >> 4;
        }
        base_src_idx += srcstride;
        base_tmp_idx += 64;
    }
}
