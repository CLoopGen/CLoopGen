#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Offsets Unrolled
    // The original loop accesses memory with small offsets (off from 0 to 3).
    // This variant unrolls the loop and uses fixed offset access to simulate
    // a more predictable strided pattern, potentially aiding vectorization.

    OPJ_UINT32 target_base = (OPJ_UINT32)(i) * 2 * 4;
    OPJ_INT32 idx_ref_curr = (1 + (OPJ_UINT32)(i) * 2) * 4;
    OPJ_INT32 idx_ref_prev = (1 + (OPJ_UINT32)(i - 1) * 2) * 4;
    OPJ_INT32 idx_ref_edge_low = (1 + (OPJ_UINT32)(0) * 2) * 4;
    OPJ_INT32 idx_ref_edge_high = (1 + (OPJ_UINT32)(dn - 1) * 2) * 4;

    // Manual unrolling for off = 0 to 3 with direct access
    for (off = 0; off < 4; ++off) {
        OPJ_INT32 neighbor_val = 0;

        // Compute neighbor value using clamped indices
        if ((i - 1) < 0 || (i - 1) >= dn) {
            OPJ_INT32 edge_idx = (i - 1) < 0 ? idx_ref_edge_low : idx_ref_edge_high;
            neighbor_val += a[edge_idx + off];
        } else {
            neighbor_val += a[idx_ref_prev + off];
        }

        if (i < 0 || i >= dn) {
            OPJ_INT32 edge_idx = i < 0 ? idx_ref_edge_low : idx_ref_edge_high;
            neighbor_val += a[edge_idx + off];
        } else {
            neighbor_val += a[idx_ref_curr + off];
        }

        a[target_base + off] -= (neighbor_val + 2) >> 2;
    }
}
