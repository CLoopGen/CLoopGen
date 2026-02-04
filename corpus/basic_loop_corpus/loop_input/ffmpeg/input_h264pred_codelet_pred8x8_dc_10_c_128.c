#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
uint16_t *src;

void init_vars() {
    // Allocate sufficient data to make the loop take ~0.01 seconds
    // The loop runs only 4 iterations, so performance bottleneck is negligible.
    // However, we must ensure memory accesses are within bounds.
    // Analyze indices used in the loop:
    //   src[-1 + i * stride] for i in [0,3] --> indices: -1, -1+stride, -1+2*stride, -1+3*stride
    //   src[i - stride] for i in [0,3] --> indices: -stride, 1-stride, 2-stride, 3-stride
    //   src[4 + i - stride] for i in [0,3] --> indices: 4-stride, 5-stride, 6-stride, 7-stride
    //   src[-1 + (i+4)*stride] for i in [0,3] --> indices: -1+4*stride, -1+5*stride, -1+6*stride, -1+7*stride

    // To avoid out-of-bounds, we need to ensure all these indices are valid.
    // The most negative index depends on 'stride'. We assume positive stride.
    // Let's assume stride >= 1. Then worst negative index is min(-1, -stride) = -stride (if stride > 1).
    // The largest positive index is max(-1+7*stride).

    // Choose a reasonable stride value that allows safe access.
    // Set stride = 1024 to provide spacing and simulate strided access pattern.
    stride = 1024;

    // Minimum index accessed: -stride (from i=0: 0 - stride = -stride)
    // Maximum index accessed: -1 + 7 * stride = -1 + 7*1024 = 7167
    // So we need array from offset at least -stride to 7167.
    // Allocate extra space: base pointer will point into the middle.

    size_t offset_negative = stride; // room for negative indices down to -stride
    size_t total_size = offset_negative + 8 * stride; // up to 8*stride to be safe

    uint16_t *base = (uint16_t*)calloc(total_size, sizeof(uint16_t));
    if (!base) exit(1);

    src = base + offset_negative; // now src[0] corresponds to base[offset_negative]
                                  // so src[-stride] = base[0], which is valid

    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
}