#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride 4 (access every other element in interleaved fashion)
    // This changes access pattern from dense to strided, potentially improving vectorization or simulating sparse update.
    // We process indices in two passes with step size 2 to create strided behavior across iterations.

    // First pass: even indices
    for (OPJ_INT32 j = i; j < win_l_x1; j += 2) {
        OPJ_INT32 left_idx = (j - 1) < 0 ? 0 : (j - 1) >= dn ? dn - 1 : j - 1;
        OPJ_INT32 curr_idx = j < 0 ? 0 : j >= dn ? dn - 1 : j;
        a[j * 2] -= ((a[1 + left_idx * 2] + a[1 + curr_idx * 2] + 2) >> 2);
    }
    // Second pass: odd indices
    for (OPJ_INT32 j = i + 1; j < win_l_x1; j += 2) {
        OPJ_INT32 left_idx = (j - 1) < 0 ? 0 : (j - 1) >= dn ? dn - 1 : j - 1;
        OPJ_INT32 curr_idx = j < 0 ? 0 : j >= dn ? dn - 1 : j;
        a[j * 2] -= ((a[1 + left_idx * 2] + a[1 + curr_idx * 2] + 2) >> 2);
    }
}
