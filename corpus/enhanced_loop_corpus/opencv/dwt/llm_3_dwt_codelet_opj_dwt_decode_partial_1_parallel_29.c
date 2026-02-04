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
    // Variant 2: Strided Memory Access with Fixed Step Expansion
    // Unroll the inner loop partially and modify access pattern to use a fixed stride
    // across a flattened index, enhancing potential for vectorization.
    for (; i < i_max; i++) {
        OPJ_UINT32 idx_current = (OPJ_UINT32)(i) * 8;
        OPJ_UINT32 idx_prev = (1 + (OPJ_UINT32)(i - 1) * 2) * 4;
        // Fully unroll the inner loop for off = 0 to 3
        a[idx_current + 0] -= (a[idx_prev + 0] + a[idx_current + 4] + 2) >> 2;
        a[idx_current + 1] -= (a[idx_prev + 1] + a[idx_current + 5] + 2) >> 2;
        a[idx_current + 2] -= (a[idx_prev + 2] + a[idx_current + 6] + 2) >> 2;
        a[idx_current + 3] -= (a[idx_prev + 3] + a[idx_current + 7] + 2) >> 2;
    }
}
