#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Pointer-based) Memory Access Pattern
    // Use pointer arithmetic with pre-incremented pointers to simulate indirect access
    uint8_t *s = src;
    uint8_t *d = dst;
    const ptrdiff_t ss = srcStride;
    const ptrdiff_t ds = dstStride;

    for (i = 0; i < w; i++) {
        // Create an array of pointers to simulate indirect access
        uint8_t *ptrs[11];
        ptrs[0] = s - 2 * ss;
        ptrs[1] = s - 1 * ss;
        ptrs[2] = s + 0 * ss;
        ptrs[3] = s + 1 * ss;
        ptrs[4] = s + 2 * ss;
        ptrs[5] = s + 3 * ss;
        ptrs[6] = s + 4 * ss;
        ptrs[7] = s + 5 * ss;
        ptrs[8] = s + 6 * ss;
        ptrs[9] = s + 7 * ss;
        ptrs[10] = s + 8 * ss;
        ptrs[11] = s + 9 * ss;
        ptrs[12] = s + 10 * ss;

        // Dereference through pointer array (indirect access)
        const int srcB = *ptrs[0];
        const int srcA = *ptrs[1];
        const int src0 = *ptrs[2];
        const int src1 = *ptrs[3];
        const int src2 = *ptrs[4];
        const int src3 = *ptrs[5];
        const int src4 = *ptrs[6];
        const int src5 = *ptrs[7];
        const int src6 = *ptrs[8];
        const int src7 = *ptrs[9];
        const int src8 = *ptrs[10];
        const int src9 = *ptrs[11];
        const int src10 = *ptrs[12];

        // Apply same filter logic using indirect loads
        d[0 * ds] = cm[((0 * srcB + -1 * srcA + 5 * src0 + 5 * src1 + -1 * src2 + 0 * src3) + 4) >> 3];
        d[1 * ds] = cm[((0 * srcA + -1 * src0 + 5 * src1 + 5 * src2 + -1 * src3 + 0 * src4) + 4) >> 3];
        d[2 * ds] = cm[((0 * src0 + -1 * src1 + 5 * src2 + 5 * src3 + -1 * src4 + 0 * src5) + 4) >> 3];
        d[3 * ds] = cm[((0 * src1 + -1 * src2 + 5 * src3 + 5 * src4 + -1 * src5 + 0 * src6) + 4) >> 3];
        d[4 * ds] = cm[((0 * src2 + -1 * src3 + 5 * src4 + 5 * src5 + -1 * src6 + 0 * src7) + 4) >> 3];
        d[5 * ds] = cm[((0 * src3 + -1 * src4 + 5 * src5 + 5 * src6 + -1 * src7 + 0 * src8) + 4) >> 3];
        d[6 * ds] = cm[((0 * src4 + -1 * src5 + 5 * src6 + 5 * src7 + -1 * src8 + 0 * src9) + 4) >> 3];
        d[7 * ds] = cm[((0 * src5 + -1 * src6 + 5 * src7 + 5 * src8 + -1 * src9 + 0 * src10) + 4) >> 3];

        // Advance base pointers
        s++;
        d++;
    }

    // Update the external variables after processing
    src = s;
    dst = d;
}
