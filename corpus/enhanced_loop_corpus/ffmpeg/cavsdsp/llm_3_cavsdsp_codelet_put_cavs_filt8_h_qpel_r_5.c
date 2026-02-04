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
    // Variant 2: Strided Memory Access via Pointer Arithmetic Unrolling
    // Restructure access to use explicit pointer arithmetic with fixed offsets (strided pattern)
    // and unroll the computation using pointer variables to simulate different stride behavior.
    uint8_t *s = src;
    uint8_t *d = dst;
    ptrdiff_t ds = dstStride;
    ptrdiff_t ss = srcStride;
    for (i = 0; i < h; i++) {
        // Use direct offset-based pointer access with precomputed indices
        uint8_t *sbase = s;
        dst[0] = cm[((0 * sbase[-2] + (-7) * sbase[-1] + 42 * sbase[0] + 96 * sbase[1] + (-2) * sbase[2] + (-1) * sbase[3]) + 64) >> 7];
        dst[1] = cm[((0 * sbase[-1] + (-7) * sbase[0]  + 42 * sbase[1] + 96 * sbase[2] + (-2) * sbase[3] + (-1) * sbase[4]) + 64) >> 7];
        dst[2] = cm[((0 * sbase[0]  + (-7) * sbase[1]  + 42 * sbase[2] + 96 * sbase[3] + (-2) * sbase[4] + (-1) * sbase[5]) + 64) >> 7];
        dst[3] = cm[((0 * sbase[1]  + (-7) * sbase[2]  + 42 * sbase[3] + 96 * sbase[4] + (-2) * sbase[5] + (-1) * sbase[6]) + 64) >> 7];
        dst[4] = cm[((0 * sbase[2]  + (-7) * sbase[3]  + 42 * sbase[4] + 96 * sbase[5] + (-2) * sbase[6] + (-1) * sbase[7]) + 64) >> 7];
        dst[5] = cm[((0 * sbase[3]  + (-7) * sbase[4]  + 42 * sbase[5] + 96 * sbase[6] + (-2) * sbase[7] + (-1) * sbase[8]) + 64) >> 7];
        dst[6] = cm[((0 * sbase[4]  + (-7) * sbase[5]  + 42 * sbase[6] + 96 * sbase[7] + (-2) * sbase[8] + (-1) * sbase[9]) + 64) >> 7];
        dst[7] = cm[((0 * sbase[5]  + (-7) * sbase[6]  + 42 * sbase[7] + 96 * sbase[8] + (-2) * sbase[9] + (-1) * sbase[10]) + 64) >> 7];
        d += ds;
        s += ss;
        dst = d;
        src = s;
    }
}
