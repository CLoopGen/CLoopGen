#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using index array (simulating irregular but predictable pattern)
    const int src_offsets[8][6] = {
        {-2, -1, 0, 1, 2, 3},
        {-1,  0, 1, 2, 3, 4},
        { 0,  1, 2, 3, 4, 5},
        { 1,  2, 3, 4, 5, 6},
        { 2,  3, 4, 5, 6, 7},
        { 3,  4, 5, 6, 7, 8},
        { 4,  5, 6, 7, 8, 9},
        { 5,  6, 7, 8, 9, 10}
    };
    const int coeffs[6] = {-1, -2, 96, 42, -7, 0};
    uint8_t *d = dst;
    uint8_t *s = src;

    for (i = 0; i < h; i++) {
        for (int j = 0; j < 8; j++) {
            int sum = 0;
            for (int k = 0; k < 6; k++) {
                sum += coeffs[k] * s[src_offsets[j][k]];
            }
            d[j] = cm[(sum + 64) >> 7];
        }
        d += dstStride;
        s += srcStride;
    }
}
