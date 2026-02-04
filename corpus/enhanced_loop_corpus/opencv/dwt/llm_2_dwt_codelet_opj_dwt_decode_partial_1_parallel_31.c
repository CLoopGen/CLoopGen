#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing strided elements, we reorganize the computation to access memory consecutively
    // by precomputing base indices and iterating over components in inner loop.
    OPJ_INT32 base_idx_1, base_idx_2, base_idx_dst;
    for (; i < i_max; i++) {
        base_idx_1 = (OPJ_UINT32)(i) * 8;           // i * 2 * 4
        base_idx_2 = (OPJ_UINT32)(i + 1) * 8;       // (i+1) * 2 * 4
        base_idx_dst = base_idx_1 + 8 + 4;          // (1 + i*2) * 4 = i*8 + 12 → simplified as base_idx_1 + 12
        // But note: (1 + i*2)*4 = 4 + 8*i → so actually it's base_idx_1 + 4 + 8? Let's recompute:
        // Correction: (1 + i*2)*4 = 4 + 8*i → base_idx_dst = 4 + 8*i = base_idx_1 + 4
        base_idx_dst = base_idx_1 + 4;
        for (off = 0; off < 4; off++) {
            a[base_idx_dst + off] += (a[base_idx_1 + off] + a[base_idx_2 + off]) >> 1;
        }
    }
}
