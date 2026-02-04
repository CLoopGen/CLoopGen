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
    // Instead of strided access with index arithmetic, reorganize the computation
    // to access memory locations consecutively by precomputing base pointers.
    OPJ_INT32 *base_current;
    OPJ_INT32 *base_prev;
    for (; i < i_max; i++) {
        base_current = &a[(OPJ_UINT32)(i) * 8];       // i * 2 * 4 = i * 8
        base_prev = &a[(1 + (OPJ_UINT32)(i - 1) * 2) * 4]; // (1 + (i-1)*2)*4
        for (off = 0; off < 4; off++) {
            base_current[off] -= (base_prev[off] + base_current[4 + off] + 2) >> 2;
        }
    }
}
