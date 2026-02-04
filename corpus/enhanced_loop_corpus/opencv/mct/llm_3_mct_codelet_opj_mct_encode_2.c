#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *restrict c0;
extern OPJ_INT32 *restrict c1;
extern OPJ_INT32 *restrict c2;
extern OPJ_SIZE_T i;
extern  OPJ_SIZE_T len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using pointer arithmetic
    // This variant uses base pointers incremented consecutively, promoting better optimization and vectorization
    OPJ_INT32 *p_c0 = c0 + i;
    OPJ_INT32 *p_c1 = c1 + i;
    OPJ_INT32 *p_c2 = c2 + i;
    OPJ_SIZE_T count = 0;
    OPJ_SIZE_T total = len - i;

    for (; count < total; ++count) {
        OPJ_INT32 r = p_c0[count];
        OPJ_INT32 g = p_c1[count];
        OPJ_INT32 b = p_c2[count];
        OPJ_INT32 y = (r + (g * 2) + b) >> 2;
        OPJ_INT32 u = b - g;
        OPJ_INT32 v = r - g;
        p_c0[count] = y;
        p_c1[count] = u;
        p_c2[count] = v;
    }
    // Note: 'i' is not updated here as it's assumed to be managed externally per original semantics
}
