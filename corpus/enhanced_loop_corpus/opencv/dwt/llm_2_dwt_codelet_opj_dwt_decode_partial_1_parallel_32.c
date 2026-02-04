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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize memory accesses to be consecutive by precomputing base indices
    // and accessing elements in a sequential manner to improve cache locality.

    OPJ_UINT32 base_idx_current, base_idx_next;
    OPJ_INT32 *ptr_a = a;  // Local pointer for potential optimization

    for (; i < win_h_x1; i++) {
        base_idx_current = (OPJ_UINT32)(i) * 8 + 4;          // (i * 2) * 4 + 0 offset base
        base_idx_next = (OPJ_UINT32)(i + 1) * 8 + 4;         // ((i+1) * 2) * 4 + 0 offset base

        OPJ_INT32 val_current_0 = (i < 0) ? ptr_a[4] : ((i >= sn) ? ptr_a[(sn - 1U) * 8 + 4] : ptr_a[base_idx_current]);
        OPJ_INT32 val_current_1 = (i < 0) ? ptr_a[5] : ((i >= sn) ? ptr_a[(sn - 1U) * 8 + 5] : ptr_a[base_idx_current + 1]);
        OPJ_INT32 val_current_2 = (i < 0) ? ptr_a[6] : ((i >= sn) ? ptr_a[(sn - 1U) * 8 + 6] : ptr_a[base_idx_current + 2]);
        OPJ_INT32 val_current_3 = (i < 0) ? ptr_a[7] : ((i >= sn) ? ptr_a[(sn - 1U) * 8 + 7] : ptr_a[base_idx_current + 3]);

        OPJ_INT32 val_next_0 = ((i + 1) < 0) ? ptr_a[4] : (((i + 1) >= sn) ? ptr_a[(sn - 1U) * 8 + 4] : ptr_a[base_idx_next]);
        OPJ_INT32 val_next_1 = ((i + 1) < 0) ? ptr_a[5] : (((i + 1) >= sn) ? ptr_a[(sn - 1U) * 8 + 5] : ptr_a[base_idx_next + 1]);
        OPJ_INT32 val_next_2 = ((i + 1) < 0) ? ptr_a[6] : (((i + 1) >= sn) ? ptr_a[(sn - 1U) * 8 + 6] : ptr_a[base_idx_next + 2]);
        OPJ_INT32 val_next_3 = ((i + 1) < 0) ? ptr_a[7] : (((i + 1) >= sn) ? ptr_a[(sn - 1U) * 8 + 7] : ptr_a[base_idx_next + 3]);

        ptr_a[base_idx_current + 0] += (val_current_0 + val_next_0) >> 1;
        ptr_a[base_idx_current + 1] += (val_current_1 + val_next_1) >> 1;
        ptr_a[base_idx_current + 2] += (val_current_2 + val_next_2) >> 1;
        ptr_a[base_idx_current + 3] += (val_current_3 + val_next_3) >> 1;
    }
}
