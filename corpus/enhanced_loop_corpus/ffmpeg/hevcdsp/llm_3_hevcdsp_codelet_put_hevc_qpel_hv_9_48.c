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
    // Variant 2: Strided Access with Fixed Offset Jumps (Unrolled Access Pattern)
    // Restructure memory access to use a constant stride through a step pointer array
    // This simulates a more cache-unfriendly strided pattern but made explicit
    const int offsets[] = {-3*64, -2*64, -64, 0, 64, 2*64, 3*64, 4*64};
    int16_t *ptrs[8];
    for (y = 0; y < height; y++) {
        // Pre-load base pointers for each offset
        for (int k = 0; k < 8; k++) {
            ptrs[k] = tmp + offsets[k];
        }
        for (x = 0; x < width; x++) {
            dst[x] = (
                filter[0] * ptrs[0][x] +
                filter[1] * ptrs[1][x] +
                filter[2] * ptrs[2][x] +
                filter[3] * ptrs[3][x] +
                filter[4] * ptrs[4][x] +
                filter[5] * ptrs[5][x] +
                filter[6] * ptrs[6][x] +
                filter[7] * ptrs[7][x]
            ) >> 6;
        }
        tmp += 64;
        dst += 64;
    }
}
