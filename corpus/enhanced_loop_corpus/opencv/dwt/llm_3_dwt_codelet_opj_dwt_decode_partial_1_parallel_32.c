#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 sn;
extern OPJ_INT32 win_h_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access Pattern
    // Transform inner loop into a strided access pattern where each iteration
    // jumps by a fixed stride (e.g., 2 or 4) across the array, simulating
    // access patterns found in matrix column traversal or SIMD-like processing.
    // Here we unroll and restructure to access every 4th element.

    OPJ_UINT32 idx_base, idx_offset;
    const OPJ_UINT32 stride = 4;

    for (; i < win_h_x1; i++) {
        idx_base = (1U + (OPJ_UINT32)i * 2) * 4;

        for (off = 0; off < 4; off += 2) {
            // Stride-2 access within the 4-element block
            OPJ_UINT32 idx1 = idx_base + off;
            OPJ_UINT32 idx2 = idx_base + off + 1;

            OPJ_INT32 left_val, right_val;

            // Left sample: current i
            left_val = (i < 0) ? a[0 * 2U * 4 + off] :
                      ((i >= sn) ? a[(sn - 1U) * 2U * 4 + off] : a[(OPJ_UINT32)i * 2U * 4 + off]);
            left_val += (i < 0) ? a[0 * 2U * 4 + off + 1] :
                       ((i >= sn) ? a[(sn - 1U) * 2U * 4 + off + 1] : a[(OPJ_UINT32)i * 2U * 4 + off + 1]);

            // Right sample: i+1
            right_val = ((i + 1) < 0) ? a[0 * 2U * 4 + off] :
                       (((i + 1) >= sn) ? a[(sn - 1U) * 2U * 4 + off] : a[(OPJ_UINT32)(i + 1) * 2U * 4 + off]);
            right_val += ((i + 1) < 0) ? a[0 * 2U * 4 + off + 1] :
                        (((i + 1) >= sn) ? a[(sn - 1U) * 2U * 4 + off + 1] : a[(OPJ_UINT32)(i + 1) * 2U * 4 + off + 1]);

            // Apply averaged update to two consecutive outputs
            a[idx1] += (left_val + right_val) >> 2;      // Divide by 2 overall -> >>1 per pair sum
            if (off + 1 < 4) {
                a[idx2] += (left_val + right_val) >> 2;
            }
        }
    }
}
