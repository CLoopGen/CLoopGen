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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing strided elements in a non-linear fashion, we precompute indices
    // and access memory consecutively to improve cache locality.
    OPJ_INT32 base_idx_current = (1 + (OPJ_UINT32)(i) * 2) * 4;
    OPJ_INT32 base_idx_prev = (1 + (OPJ_UINT32)(i - 1) * 2) * 4;
    OPJ_INT32 base_idx_0 = (1 + (OPJ_UINT32)(0) * 2) * 4;
    OPJ_INT32 base_idx_dn_minus_1 = (1 + (OPJ_UINT32)(dn - 1) * 2) * 4;
    OPJ_INT32 target_base = (OPJ_UINT32)(i) * 2 * 4;

    for (off = 0; off < 4; off++) {
        OPJ_INT32 val_prev, val_curr;

        // Handle boundary conditions for i-1
        if ((i - 1) < 0) {
            val_prev = a[base_idx_0 + off];
        } else if ((i - 1) >= dn) {
            val_prev = a[base_idx_dn_minus_1 + off];
        } else {
            val_prev = a[base_idx_prev + off];
        }

        // Handle boundary conditions for i
        if (i < 0) {
            val_curr = a[base_idx_0 + off];
        } else if (i >= dn) {
            val_curr = a[base_idx_dn_minus_1 + off];
        } else {
            val_curr = a[base_idx_current + off];
        }

        a[target_base + off] -= (val_prev + val_curr + 2) >> 2;
    }
}
