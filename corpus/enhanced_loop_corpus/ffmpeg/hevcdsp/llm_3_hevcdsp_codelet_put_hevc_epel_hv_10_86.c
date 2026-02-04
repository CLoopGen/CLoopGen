#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using indirect indexing via precomputed offsets
    // We precompute the effective memory offsets relative to current row,
    // simulating a more irregular or configurable access pattern.
    const int stride = 64;
    const int offsets[4] = {-stride, 0, stride, 2*stride}; // Relative positions
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += filter[k] * tmp[x + offsets[k]];
            }
            dst[x] = sum >> 6;
        }
        tmp += 64;
        dst += 64;
    }
}
